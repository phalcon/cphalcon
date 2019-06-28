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
    'file' => '/app/phalcon/Tag.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Tag.zep',
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
        'name' => 'Phalcon\\Tag\\Select',
        'file' => '/app/phalcon/Tag.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Tag.zep',
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
        'name' => 'Phalcon\\Tag\\Exception',
        'file' => '/app/phalcon/Tag.zep',
        'line' => 14,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Tag.zep',
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
        'name' => 'Phalcon\\UrlInterface',
        'file' => '/app/phalcon/Tag.zep',
        'line' => 15,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Tag.zep',
    'line' => 21,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 *',
    'file' => '/app/phalcon/Tag.zep',
    'line' => 22,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Tag',
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
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'autoEscape',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 36,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 40,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'container',
          'docblock' => '**
     * Framework Dispatcher
     *',
          'file' => '/app/phalcon/Tag.zep',
          'line' => 45,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'displayValues',
          'docblock' => '**
     * Pre-assigned values for components
     *',
          'file' => '/app/phalcon/Tag.zep',
          'line' => 48,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'dispatcherService',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 48,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 50,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'documentAppendTitle',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 50,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 52,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'documentPrependTitle',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 52,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 56,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'documentTitle',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 57,
            'char' => 42,
          ),
          'docblock' => '**
     * HTML document title
     *',
          'file' => '/app/phalcon/Tag.zep',
          'line' => 59,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'documentTitleSeparator',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 59,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 61,
          'char' => 13,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'documentType',
          'default' => 
          array (
            'type' => 'int',
            'value' => '11',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 61,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 63,
          'char' => 13,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'escaperService',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 63,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 65,
          'char' => 13,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'urlService',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Tag.zep',
            'line' => 65,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 69,
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
            1 => 'static',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 70,
              'char' => 49,
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
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 72,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'documentAppendTitle',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 72,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 72,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 72,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 72,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'documentAppendTitle',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 73,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 73,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 74,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 76,
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
                    'value' => 'title',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 76,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 76,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 76,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 76,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'documentAppendTitle',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'title',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 77,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 77,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 78,
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
                      'assign-type' => 'static-property-append',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'documentAppendTitle',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'title',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 79,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 79,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 80,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a text to current document title
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 70,
          'last-line' => 101,
          'char' => 26,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'checkField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 102,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputFieldChecked',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'checkbox',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 104,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 104,
                    'char' => 48,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 104,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 104,
                    'char' => 60,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 104,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 105,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="check"] tag
     *
     *```php
     * echo Phalcon\\Tag::checkField(
     *     [
     *         "terms",
     *         "value" => "Y",
     *     ]
     * );
     *```
     *
     * Volt syntax:
     *```php
     * {{ check_field("terms") }}
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 103,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 103,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 102,
          'last-line' => 111,
          'char' => 26,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'colorField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 112,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'color',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 114,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 114,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 114,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 114,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 114,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 115,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="color"] tag
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 113,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 113,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 112,
          'last-line' => 130,
          'char' => 26,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'dateField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 131,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'date',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 133,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 133,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 133,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 133,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 133,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 134,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="date"] tag
     *
     * ```php
     * echo Phalcon\\Tag::dateField(
     *     [
     *         "born",
     *         "value" => "14-12-1980",
     *     ]
     * );
     * ```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 132,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 132,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 131,
          'last-line' => 140,
          'char' => 26,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'dateTimeField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 141,
              'char' => 56,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'datetime',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 143,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 143,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 143,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 143,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 143,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 144,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Builds a HTML input[type="datetime"] tag
    *
    * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 142,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 142,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 141,
          'last-line' => 150,
          'char' => 26,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'dateTimeLocalField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 151,
              'char' => 61,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'datetime-local',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 153,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 153,
                    'char' => 47,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 153,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 153,
                    'char' => 59,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 153,
                'char' => 60,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 154,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Builds a HTML input[type="datetime-local"] tag
    *
    * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 152,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 152,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 151,
          'last-line' => 160,
          'char' => 26,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'displayTo',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 161,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 161,
              'char' => 55,
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
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'setDefault',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'id',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 163,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 163,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 163,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 163,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 163,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 164,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Alias of Phalcon\\Tag::setDefault()
     *
     * @param string value
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 162,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 161,
          'last-line' => 174,
          'char' => 26,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'emailField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 175,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'email',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 177,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 177,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 177,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 177,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 177,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 178,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="email"] tag
     *
     * ```php
     * echo Phalcon\\Tag::emailField("email");
     * ```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 176,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 176,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 175,
          'last-line' => 182,
          'char' => 26,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'endForm',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '</form>',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 185,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 186,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML close FORM tag
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 184,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 184,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 183,
          'last-line' => 196,
          'char' => 26,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'fileField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 197,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'file',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 199,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 199,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 199,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 199,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 199,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 200,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="file"] tag
     *
     *```php
     * echo Phalcon\\Tag::fileField("file");
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 198,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 198,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 197,
          'last-line' => 223,
          'char' => 26,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'form',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 224,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 226,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'paramsAction',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 226,
                  'char' => 33,
                ),
                2 => 
                array (
                  'variable' => 'action',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 226,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 226,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 228,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 228,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 228,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 228,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 228,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 229,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 229,
                            'char' => 37,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 229,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 229,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 230,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 231,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 231,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 232,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 234,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paramsAction',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 234,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 234,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 234,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 234,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 234,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 234,
                'char' => 43,
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
                      'value' => 'paramsAction',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 235,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 235,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'action',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 235,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 235,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 235,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 236,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 241,
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 241,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'method',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 241,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 241,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 241,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 241,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'method',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 242,
                          'char' => 30,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'post',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 242,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 242,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 243,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 245,
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
                  'variable' => 'action',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 245,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 245,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 247,
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
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paramsAction',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 247,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 247,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 247,
                'char' => 32,
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
                      'variable' => 'action',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'self',
                          'dynamic' => 0,
                          'name' => 'getUrlService',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 248,
                          'char' => 48,
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
                              'value' => 'paramsAction',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 248,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 248,
                            'char' => 65,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 248,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 248,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 249,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 254,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 254,
                  'char' => 49,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 254,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 254,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 254,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 254,
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
                      'variable' => 'action',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '?',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 255,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 255,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 255,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 255,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 256,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 258,
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
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'action',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 258,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 258,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 258,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'action',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 259,
                          'char' => 30,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'action',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 259,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 259,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 260,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 262,
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
                  'operator' => 'assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '<form',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 262,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 262,
                        'char' => 48,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 262,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 262,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 262,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 262,
                  'char' => 57,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '>',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 263,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 263,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 265,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 265,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 266,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML FORM tag
     *
     * ```php
     * echo Phalcon\\Tag::form("posts/save");
     *
     * echo Phalcon\\Tag::form(
     *     [
     *         "posts/save",
     *         "method" => "post",
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {{ form("posts/save") }}
     * {{ form("posts/save", "method": "post") }}
     * ```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 225,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 225,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 224,
          'last-line' => 274,
          'char' => 26,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 276,
              'char' => 20,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'separator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '-',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 277,
                'char' => 29,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 277,
              'char' => 29,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'lowercase',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 278,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 278,
              'char' => 30,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'replace',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 280,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 280,
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
                  'variable' => 'friendly',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 282,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'locale',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 282,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'search',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 282,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 284,
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
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 284,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 284,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 284,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 288,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 288,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'en_US.UTF-8',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 288,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 288,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 288,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 288,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 289,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 289,
                            'char' => 35,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'ASCII//TRANSLIT',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 289,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 289,
                            'char' => 52,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 289,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 289,
                            'char' => 58,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 289,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 289,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 290,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 292,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'replace',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 292,
                'char' => 20,
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
                          'type' => 'not-equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'replace',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 293,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 293,
                            'char' => 42,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 293,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 293,
                          'char' => 51,
                        ),
                        'right' => 
                        array (
                          'type' => 'not-equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'replace',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 293,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 293,
                            'char' => 69,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 293,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 293,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 293,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 293,
                      'char' => 79,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 293,
                    'char' => 79,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 296,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 296,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 296,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 297,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 299,
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
                        'value' => 'replace',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 299,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 299,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 299,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 299,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'replace',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 300,
                        'char' => 39,
                      ),
                      'value' => 'search',
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
                                      'value' => 'search',
                                      'file' => '/app/phalcon/Tag.zep',
                                      'line' => 301,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 301,
                                    'char' => 50,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ' ',
                                      'file' => '/app/phalcon/Tag.zep',
                                      'line' => 301,
                                      'char' => 53,
                                    ),
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 301,
                                    'char' => 53,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'text',
                                      'file' => '/app/phalcon/Tag.zep',
                                      'line' => 301,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 301,
                                    'char' => 59,
                                  ),
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 301,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 301,
                              'char' => 60,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 302,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 303,
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
                                  'value' => 'replace',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 304,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 304,
                                'char' => 47,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 304,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 304,
                                'char' => 50,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'text',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 304,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 304,
                                'char' => 56,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 304,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 304,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 305,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 306,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 308,
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
                  'variable' => 'friendly',
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 309,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 309,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 310,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 310,
                        'char' => 13,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 312,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 312,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 312,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 312,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 314,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'lowercase',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 314,
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
                      'variable' => 'friendly',
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
                              'value' => 'friendly',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 315,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 315,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 315,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 315,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 316,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 318,
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
                  'variable' => 'friendly',
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 318,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 318,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'separator',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 318,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 318,
                        'char' => 61,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'friendly',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 318,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 318,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 318,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 318,
                  'char' => 72,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'friendly',
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
                          'value' => 'friendly',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 319,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 319,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'separator',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 319,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 319,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 319,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 319,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 321,
              'char' => 10,
            ),
            6 => 
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
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 321,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 321,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 321,
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 325,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 325,
                        'char' => 29,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'locale',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 325,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 325,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 325,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 326,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 327,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'friendly',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 327,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 328,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Converts texts into URL-friendly titles
     *
     *```php
     * echo Phalcon\\Tag::friendlyTitle("These are big important news", "-")
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Tag.zep',
                'line' => 281,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 281,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 275,
          'last-line' => 332,
          'char' => 26,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
                'type' => 'static-property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'self',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 336,
                  'char' => 9,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'documentType',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 336,
                  'char' => 9,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 336,
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
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 337,
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 337,
                          'char' => 87,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 337,
                          'char' => 96,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 337,
                        'char' => 96,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 340,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 340,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '2',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 340,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 340,
                              'char' => 81,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 340,
                              'char' => 91,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 340,
                            'char' => 91,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/html4/strict.dtd\\">',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 340,
                            'char' => 138,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 340,
                          'char' => 138,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 340,
                          'char' => 147,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 340,
                        'char' => 147,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 343,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 343,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '3',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 343,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 343,
                              'char' => 94,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 343,
                              'char' => 104,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 343,
                            'char' => 104,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/html4/loose.dtd\\">',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 343,
                            'char' => 150,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 343,
                          'char' => 150,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 343,
                          'char' => 159,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 343,
                        'char' => 159,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 346,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 346,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '4',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 346,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 346,
                              'char' => 90,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 346,
                              'char' => 100,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 346,
                            'char' => 100,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/html4/frameset.dtd\\">',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 346,
                            'char' => 149,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 346,
                          'char' => 149,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 346,
                          'char' => 158,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 346,
                        'char' => 158,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 349,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 349,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '6',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 349,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 349,
                              'char' => 88,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 349,
                              'char' => 98,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 349,
                            'char' => 98,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\\">',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 349,
                            'char' => 157,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 349,
                          'char' => 157,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 349,
                          'char' => 166,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 349,
                        'char' => 166,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 352,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 352,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '7',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 352,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 352,
                              'char' => 94,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 352,
                              'char' => 103,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 352,
                            'char' => 103,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\\">',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 352,
                            'char' => 167,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 352,
                          'char' => 167,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 352,
                          'char' => 176,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 352,
                        'char' => 176,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 355,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 355,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '8',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 355,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 355,
                              'char' => 90,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 355,
                              'char' => 100,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 355,
                            'char' => 100,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\\">',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 355,
                            'char' => 161,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 355,
                          'char' => 161,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 355,
                          'char' => 170,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 355,
                        'char' => 170,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 358,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 358,
                  'char' => 16,
                ),
                7 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '9',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 358,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 358,
                              'char' => 81,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 358,
                              'char' => 91,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 358,
                            'char' => 91,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\\">',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 358,
                            'char' => 145,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 358,
                          'char' => 145,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 358,
                          'char' => 154,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 358,
                        'char' => 154,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 361,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 361,
                  'char' => 16,
                ),
                8 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '10',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 361,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 361,
                              'char' => 81,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 361,
                              'char' => 91,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 361,
                            'char' => 91,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\\">',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 361,
                            'char' => 140,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 361,
                          'char' => 140,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 361,
                          'char' => 149,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 361,
                        'char' => 149,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 364,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 364,
                  'char' => 16,
                ),
                9 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '5',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 364,
                    'char' => 19,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 365,
                  'char' => 16,
                ),
                10 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '11',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 365,
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
                          'type' => 'string',
                          'value' => '<!DOCTYPE html>',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 365,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 365,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 365,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 367,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 367,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 369,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 369,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 370,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the document type declaration of content
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 334,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 334,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 333,
          'last-line' => 374,
          'char' => 26,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getEscaper',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 375,
              'char' => 52,
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
                  'variable' => 'autoescape',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 377,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 379,
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
                    'value' => 'autoescape',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 379,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 379,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'escape',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 379,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 379,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 379,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 379,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'autoescape',
                      'expr' => 
                      array (
                        'type' => 'static-property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 380,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'autoEscape',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 380,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 380,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 380,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 381,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 383,
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
                  'value' => 'autoescape',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 383,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 383,
                'char' => 24,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 384,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 385,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 387,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'getEscaperService',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 387,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 388,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Obtains the \'escaper\' service if required
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
                  'value' => 'EscaperInterface',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 375,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Tag.zep',
                'line' => 375,
                'char' => 76,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Tag.zep',
                'line' => 376,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 376,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 375,
          'last-line' => 392,
          'char' => 26,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getDI',
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
                  'variable' => 'di',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 395,
                  'char' => 15,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 397,
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
                  'variable' => 'di',
                  'expr' => 
                  array (
                    'type' => 'static-property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 397,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 397,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 397,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 397,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 399,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'di',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 399,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 399,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 399,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 399,
                'char' => 32,
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
                      'variable' => 'di',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Di',
                        'dynamic' => 0,
                        'name' => 'getDefault',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 400,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 400,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 401,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 403,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'di',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 403,
                'char' => 18,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 404,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Internally gets the request dispatcher
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
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 394,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Tag.zep',
                'line' => 394,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 394,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 393,
          'last-line' => 408,
          'char' => 26,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getEscaperService',
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
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 411,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 411,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 413,
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
                    'type' => 'static-property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 413,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'escaperService',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 413,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 413,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 413,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 415,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'escaper',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 415,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 415,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 415,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 415,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'getDI',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 416,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 416,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 418,
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 418,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 418,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 418,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 418,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 418,
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
                                    'type' => 'string',
                                    'value' => 'the \'escaper\' service',
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 420,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 420,
                                  'char' => 78,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 421,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 421,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 421,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 422,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 424,
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
                      'variable' => 'escaper',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'EscaperInterface',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 424,
                          'char' => 75,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 424,
                            'char' => 56,
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
                                'value' => 'escaper',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 424,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 424,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 424,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 424,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 424,
                      'char' => 75,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'escaperService',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'escaper',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 425,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 425,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 426,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 428,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'escaper',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 428,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 429,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an Escaper service from the default DI
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
                  'value' => 'EscaperInterface',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 410,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Tag.zep',
                'line' => 410,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 410,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 409,
          'last-line' => 449,
          'char' => 26,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 450,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 450,
              'char' => 56,
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 450,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 450,
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
                  'variable' => 'items',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 452,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 452,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'title',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 452,
                  'char' => 33,
                ),
                3 => 
                array (
                  'variable' => 'documentTitle',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 452,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'documentAppendTitle',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 452,
                  'char' => 69,
                ),
                5 => 
                array (
                  'variable' => 'documentPrependTitle',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 453,
                  'char' => 33,
                ),
                6 => 
                array (
                  'variable' => 'documentTitleSeparator',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 453,
                  'char' => 57,
                ),
                7 => 
                array (
                  'variable' => 'escaper',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 453,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 455,
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
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'EscaperInterface',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 455,
                      'char' => 74,
                    ),
                    'right' => 
                    array (
                      'type' => 'scall',
                      'dynamic-class' => 0,
                      'class' => 'self',
                      'dynamic' => 0,
                      'name' => 'getEscaper',
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
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'escape',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 455,
                                  'char' => 66,
                                ),
                                'value' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 455,
                                  'char' => 72,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 455,
                                'char' => 72,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 455,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 455,
                          'char' => 73,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 455,
                      'char' => 74,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 455,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 455,
                  'char' => 74,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 456,
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
                  'variable' => 'items',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 456,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 456,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 457,
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
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 457,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 457,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 458,
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
                  'variable' => 'documentTitle',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'escaper',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 458,
                      'char' => 37,
                    ),
                    'name' => 'escapeHtml',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 458,
                            'char' => 68,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'documentTitle',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 458,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 458,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 458,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 458,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 458,
                  'char' => 69,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 460,
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
                  'variable' => 'documentTitleSeparator',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'escaper',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 460,
                      'char' => 46,
                    ),
                    'name' => 'escapeHtml',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 462,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'documentTitleSeparator',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 462,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 462,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 462,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 462,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 462,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 464,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'prepend',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 464,
                'char' => 20,
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
                      'type' => 'static-property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 465,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'documentPrependTitle',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 465,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 465,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 465,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 465,
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
                          'assign-type' => 'static-property',
                          'operator' => 'assign',
                          'variable' => 'self',
                          'property' => 'documentPrependTitle',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 466,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 466,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 467,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 469,
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
                      'variable' => 'documentPrependTitle',
                      'expr' => 
                      array (
                        'type' => 'static-property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 469,
                          'char' => 66,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'documentPrependTitle',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 469,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 469,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 469,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 471,
                  'char' => 14,
                ),
                2 => 
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
                        'value' => 'documentPrependTitle',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 471,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 471,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 471,
                    'char' => 44,
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
                          'variable' => 'tmp',
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
                                  'value' => 'documentPrependTitle',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 472,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 472,
                                'char' => 61,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 472,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 472,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 474,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tmp',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 474,
                        'char' => 34,
                      ),
                      'value' => 'title',
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
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 475,
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
                                      'value' => 'title',
                                      'file' => '/app/phalcon/Tag.zep',
                                      'line' => 475,
                                      'char' => 60,
                                    ),
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 475,
                                    'char' => 60,
                                  ),
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 475,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 475,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 476,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 477,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 478,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 480,
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
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'documentTitle',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 480,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 480,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 480,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'items',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'documentTitle',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 481,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 481,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 482,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 484,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'append',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 484,
                'char' => 19,
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
                      'type' => 'static-property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 485,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'documentAppendTitle',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 485,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 485,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 485,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 485,
                    'char' => 51,
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
                          'assign-type' => 'static-property',
                          'operator' => 'assign',
                          'variable' => 'self',
                          'property' => 'documentAppendTitle',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 486,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 486,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 487,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 489,
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
                      'variable' => 'documentAppendTitle',
                      'expr' => 
                      array (
                        'type' => 'static-property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 489,
                          'char' => 64,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'documentAppendTitle',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 489,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 489,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 489,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 491,
                  'char' => 14,
                ),
                2 => 
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
                        'value' => 'documentAppendTitle',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 491,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 491,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 491,
                    'char' => 43,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'documentAppendTitle',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 492,
                        'char' => 50,
                      ),
                      'value' => 'title',
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
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 493,
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
                                      'value' => 'title',
                                      'file' => '/app/phalcon/Tag.zep',
                                      'line' => 493,
                                      'char' => 60,
                                    ),
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 493,
                                    'char' => 60,
                                  ),
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 493,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 493,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 494,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 495,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 496,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 498,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'documentTitleSeparator',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 498,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 498,
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
                      'variable' => 'documentTitleSeparator',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 499,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 499,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 500,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 502,
              'char' => 10,
            ),
            10 => 
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
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 502,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 502,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 502,
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
                              'value' => 'documentTitleSeparator',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 503,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 503,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'items',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 503,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 503,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 503,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 503,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 504,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 506,
              'char' => 14,
            ),
            11 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 506,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 507,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the current document title.
     * The title will be automatically escaped.
     *
     * ```php
     * Tag::prependTitle(\'Hello\');
     * Tag::setTitle(\'World\');
     * Tag::appendTitle(\'from Phalcon\');
     *
     * echo Tag::getTitle();             // Hello World from Phalcon
     * echo Tag::getTitle(false);        // World from Phalcon
     * echo Tag::getTitle(true, false);  // Hello World
     * echo Tag::getTitle(false, false); // World
     * ```
     *
     * ```php
     * {{ get_title() }}
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 451,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 451,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 450,
          'last-line' => 519,
          'char' => 26,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
                'type' => 'static-property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'self',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 522,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'documentTitleSeparator',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 522,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 522,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 523,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the current document title separator
     *
     * ```php
     * echo Phalcon\\Tag::getTitleSeparator();
     * ```
     *
     * ```php
     * {{ get_title_separator() }}
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 521,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 521,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 520,
          'last-line' => 527,
          'char' => 26,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getUrlService',
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
                  'variable' => 'url',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 530,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 530,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 532,
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
                  'variable' => 'url',
                  'expr' => 
                  array (
                    'type' => 'static-property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 532,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'urlService',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 532,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 532,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 532,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 534,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'url',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 534,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 534,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 534,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 534,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'getDI',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 535,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 535,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 537,
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 537,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 537,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 537,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 537,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 537,
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
                                    'type' => 'string',
                                    'value' => 'the \'url\' service',
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 539,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 539,
                                  'char' => 74,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 540,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 540,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 540,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 541,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 543,
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
                      'variable' => 'url',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'UrlInterface',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 543,
                          'char' => 63,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 543,
                            'char' => 48,
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
                                'value' => 'url',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 543,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 543,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 543,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 543,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 543,
                      'char' => 63,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'urlService',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'url',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 544,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 544,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 545,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 547,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'url',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 547,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 548,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a URL service from the default DI
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
                  'value' => 'UrlInterface',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 529,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Tag.zep',
                'line' => 529,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 529,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 528,
          'last-line' => 556,
          'char' => 26,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 557,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 557,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 557,
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
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 559,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 561,
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
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 561,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 561,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 561,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 561,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 561,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 561,
                'char' => 40,
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
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 565,
                        'char' => 56,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'static-property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 565,
                            'char' => 49,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'displayValues',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 565,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 565,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 565,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 565,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 565,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 565,
                    'char' => 56,
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
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 569,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => '_POST',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 569,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 569,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 569,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 569,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 569,
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
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 570,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 571,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 572,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 573,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 575,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 575,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 576,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Every helper calls this function to check whether a component has a
     * predefined value using Phalcon\\Tag::setDefault() or value from $_POST
     *
     * @param string name
     * @return mixed
     *',
          'file' => '/app/phalcon/Tag.zep',
          'line' => 557,
          'last-line' => 583,
          'char' => 26,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 584,
              'char' => 45,
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
                      'type' => 'static-property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 589,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'displayValues',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 589,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 589,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 589,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 589,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 589,
                  'char' => 49,
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
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 589,
                      'char' => 62,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 589,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 589,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 589,
                  'char' => 68,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 589,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 590,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a helper has a default value set using Phalcon\\Tag::setDefault()
     * or value from $_POST
     *
     * @param string name
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 585,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 585,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 584,
          'last-line' => 605,
          'char' => 26,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'hiddenField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 606,
              'char' => 54,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'hidden',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 608,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 608,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 608,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 608,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 608,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 609,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="hidden"] tag
     *
     *```php
     * echo Phalcon\\Tag::hiddenField(
     *     [
     *         "name",
     *         "value" => "mike",
     *     ]
     * );
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 607,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 607,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 606,
          'last-line' => 633,
          'char' => 26,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'image',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 634,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 634,
              'char' => 55,
            ),
            1 => 
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 634,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 634,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 636,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 636,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'src',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 636,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 638,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 638,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 638,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 638,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 638,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 639,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 639,
                            'char' => 37,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 639,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 639,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 640,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 641,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 641,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 643,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 643,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 643,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 643,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 643,
                    'char' => 32,
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
                          'variable' => 'local',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'bool',
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'params',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 644,
                                'char' => 42,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 644,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 644,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 644,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 644,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 645,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 646,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 648,
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
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 648,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'src',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 648,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 648,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 648,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 648,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'src',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 649,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 649,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 649,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 649,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 649,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'src',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 650,
                              'char' => 31,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'src',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 650,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 650,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 651,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'src',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 652,
                              'char' => 31,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 652,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 652,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 653,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 654,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 659,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'local',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 659,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 660,
                          'char' => 27,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'self',
                          'dynamic' => 0,
                          'name' => 'getUrlService',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 660,
                          'char' => 53,
                        ),
                        'name' => 'getStatic',
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
                                'value' => 'params',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 660,
                                'char' => 70,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'src',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 660,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 660,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 660,
                            'char' => 75,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 660,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 660,
                      'char' => 76,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 661,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 663,
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
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '<img',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 663,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 663,
                        'char' => 47,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 663,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 663,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 663,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 663,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 668,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 668,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'documentType',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 668,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 668,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 668,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'HTML5',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 668,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 668,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 668,
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
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => ' />',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 669,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 669,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 670,
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
                      'operator' => 'concat-assign',
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '>',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 671,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 671,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 672,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 674,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 674,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 675,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds HTML IMG tags
     *
     * ```php
     * echo Phalcon\\Tag::image("img/bg.png");
     *
     * echo Phalcon\\Tag::image(
     *     [
     *         "img/photo.jpg",
     *         "alt" => "Some Photo",
     *     ]
     * );
     * ```
     *
     * Volt Syntax:
     * ```php
     * {{ image("img/bg.png") }}
     * {{ image("img/photo.jpg", "alt": "Some Photo") }}
     * {{ image("http://static.mywebsite.com/img/bg.png", false) }}
     * ```
     *
     * @param  array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 635,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 635,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 634,
          'last-line' => 694,
          'char' => 26,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'imageInput',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 695,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'image',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 697,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 697,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 697,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 697,
                    'char' => 50,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 697,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 697,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 697,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 698,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="image"] tag
     *
     *```php
     * echo Phalcon\\Tag::imageInput(
     *     [
     *         "src" => "/img/button.png",
     *     ]
     * );
     *```
     *
     * Volt syntax:
     *```php
     * {{ image_input("src": "/img/button.png") }}
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 696,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 696,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 695,
          'last-line' => 719,
          'char' => 26,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'javascriptInclude',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 720,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 720,
              'char' => 67,
            ),
            1 => 
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 720,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 720,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 722,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 722,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 724,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 724,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 724,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 724,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 724,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 725,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 725,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'local',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 725,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 725,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 725,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 725,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 726,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 727,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 727,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 728,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 730,
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
                    'value' => 'params',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 730,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 730,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 730,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Tag.zep',
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
                      'variable' => 'local',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'bool',
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'params',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 731,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 731,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 731,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 731,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 731,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 732,
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
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 733,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'local',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 733,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 733,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 733,
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
                          'variable' => 'local',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'bool',
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'params',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 734,
                                'char' => 42,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'local',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 734,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 734,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 734,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 734,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 736,
                      'char' => 21,
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 736,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'local',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 736,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 736,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 737,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 738,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 740,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
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
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 740,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'type',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 740,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 740,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 740,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 740,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'less',
                  'left' => 
                  array (
                    'type' => 'static-property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 740,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'documentType',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 740,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 740,
                    'char' => 54,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 740,
                      'char' => 68,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'HTML5',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 740,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 740,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 740,
                  'char' => 68,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 740,
                'char' => 68,
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
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 741,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'text/javascript',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 741,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 741,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 742,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 744,
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 744,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'src',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 744,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 744,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 744,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 744,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
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
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 745,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 745,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 745,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 745,
                    'char' => 32,
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
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'src',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 746,
                              'char' => 31,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 746,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 746,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 746,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 746,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 747,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'src',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 748,
                              'char' => 31,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 748,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 748,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 749,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 750,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 755,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'local',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 755,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 756,
                          'char' => 27,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'self',
                          'dynamic' => 0,
                          'name' => 'getUrlService',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 756,
                          'char' => 53,
                        ),
                        'name' => 'getStatic',
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
                                'value' => 'params',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 756,
                                'char' => 70,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'src',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 756,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 756,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 756,
                            'char' => 75,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 756,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 756,
                      'char' => 76,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 757,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 759,
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
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '<script',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 759,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 759,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 759,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 759,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 759,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 759,
                  'char' => 59,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => '></script>',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 760,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'PHP_EOL',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 760,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 760,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 760,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 762,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 762,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 763,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a SCRIPT[type="javascript"] tag
     *
     * ```php
     * echo Phalcon\\Tag::javascriptInclude(
     *     "http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js",
     *     false
     * );
     *
     * echo Phalcon\\Tag::javascriptInclude("javascript/jquery.js");
     * ```
     *
     * Volt syntax:
     * ```php
     * {{ javascript_include("http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js", false) }}
     * {{ javascript_include("javascript/jquery.js") }}
     * ```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 721,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 721,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 720,
          'last-line' => 818,
          'char' => 26,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'linkTo',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 819,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 819,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 819,
              'char' => 58,
            ),
            2 => 
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 819,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 819,
              'char' => 72,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 821,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'action',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 821,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'query',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 821,
                  'char' => 34,
                ),
                3 => 
                array (
                  'variable' => 'url',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 821,
                  'char' => 39,
                ),
                4 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 821,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 823,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 823,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 823,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 823,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 823,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 824,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 824,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 824,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 824,
                            'char' => 43,
                          ),
                          2 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'local',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 824,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 824,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 824,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 824,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 825,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 826,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 826,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 827,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 829,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'action',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 829,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 829,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 829,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 829,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 829,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 829,
                'char' => 37,
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
                        'value' => 'action',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 830,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 830,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'action',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 830,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 830,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 830,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 830,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'action',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 831,
                            'char' => 30,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 831,
                          'char' => 30,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 832,
                      'char' => 13,
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 833,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'action',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 833,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 833,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 834,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 835,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 837,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'text',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 837,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 837,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 837,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 837,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 837,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 837,
                'char' => 35,
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
                        'value' => 'text',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 838,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 838,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'text',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 838,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 838,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 838,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 838,
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
                          'variable' => 'text',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 839,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 839,
                          'char' => 28,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 840,
                      'char' => 13,
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 841,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'text',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 841,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 841,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 842,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 843,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 845,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'local',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 845,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 845,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '2',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 845,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 845,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 845,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 845,
                'char' => 36,
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
                        'value' => 'local',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 846,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 846,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'local',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 846,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 846,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 846,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 846,
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
                          'variable' => 'local',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 847,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 847,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 848,
                      'char' => 13,
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 849,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'local',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 849,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 849,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 850,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 851,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 853,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'query',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 853,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 853,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'query',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 853,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 853,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 853,
                'char' => 39,
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
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 854,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'query',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 854,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 854,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 855,
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
                      'variable' => 'query',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 856,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 856,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 857,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 859,
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
                  'variable' => 'url',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'getUrlService',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 859,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 859,
                  'char' => 40,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'href',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 860,
                      'char' => 24,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'url',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 860,
                      'char' => 32,
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 860,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 860,
                        'char' => 43,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'query',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 860,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 860,
                        'char' => 50,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'local',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 860,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 860,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 860,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 860,
                  'char' => 58,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '<a',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 861,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 861,
                        'char' => 45,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 861,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 861,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 861,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 861,
                  'char' => 54,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '>',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 862,
                        'char' => 22,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'text',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 862,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 862,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</a>',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 862,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 862,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 862,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 864,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 864,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 865,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML A tag using framework conventions
     *
     *```php
     * echo Phalcon\\Tag::linkTo("signup/register", "Register Here!");
     *
     * echo Phalcon\\Tag::linkTo(
     *     [
     *         "signup/register",
     *         "Register Here!"
     *     ]
     * );
     *
     * echo Phalcon\\Tag::linkTo(
     *     [
     *         "signup/register",
     *         "Register Here!",
     *         "class" => "btn-primary",
     *     ]
     * );
     *
     * echo Phalcon\\Tag::linkTo("http://phalconphp.com/", "Phalcon", false);
     *
     * echo Phalcon\\Tag::linkTo(
     *     [
     *         "http://phalconphp.com/",
     *         "Phalcon Home",
     *         false,
     *     ]
     * );
     *
     * echo Phalcon\\Tag::linkTo(
     *     [
     *         "http://phalconphp.com/",
     *         "Phalcon Home",
     *         "local" => false,
     *     ]
     * );
     *
     * echo Phalcon\\Tag::linkTo(
     *     [
     *         "action" => "http://phalconphp.com/",
     *         "text"   => "Phalcon Home",
     *         "local"  => false,
     *         "target" => "_new"
     *     ]
     * );
     *
     *```
     *
     * @param array|string parameters
     * @param string text
     * @param bool local
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 820,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 820,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 819,
          'last-line' => 871,
          'char' => 26,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'monthField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 872,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'month',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 874,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 874,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 874,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 874,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 874,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 875,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="month"] tag
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 873,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 873,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 872,
          'last-line' => 891,
          'char' => 26,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'numericField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 892,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'number',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 894,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 894,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 894,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 894,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 894,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 895,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="number"] tag
     *
     * ```php
     * echo Phalcon\\Tag::numericField(
     *     [
     *         "price",
     *         "min" => "1",
     *         "max" => "5",
     *     ]
     * );
     * ```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 893,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 893,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 892,
          'last-line' => 911,
          'char' => 26,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'passwordField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 912,
              'char' => 56,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'password',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 914,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 914,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 914,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 914,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 914,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 915,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="password"] tag
     *
     *```php
     * echo Phalcon\\Tag::passwordField(
     *     [
     *         "name",
     *         "size" => 30,
     *     ]
     * );
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 913,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 913,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 912,
          'last-line' => 919,
          'char' => 26,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 920,
              'char' => 50,
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
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 922,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'documentPrependTitle',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 922,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 922,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 922,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 922,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'documentPrependTitle',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 923,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 923,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 924,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 926,
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
                    'value' => 'title',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 926,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 926,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 926,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 926,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'documentPrependTitle',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'title',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 927,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 927,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 928,
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
                      'assign-type' => 'static-property-append',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'documentPrependTitle',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'title',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 929,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 929,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 930,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 931,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prepends a text to current document title
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 921,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 920,
          'last-line' => 951,
          'char' => 26,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'radioField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 952,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputFieldChecked',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'radio',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 954,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 954,
                    'char' => 45,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 954,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 954,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 954,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 955,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="radio"] tag
     *
     *```php
     * echo Phalcon\\Tag::radioField(
     *     [
     *         "weather",
     *         "value" => "hot",
     *     ]
     * );
     *```
     *
     * Volt syntax:
     *```php
     * {{ radio_field("Save") }}
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 953,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 953,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 952,
          'last-line' => 961,
          'char' => 26,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'rangeField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 962,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'range',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 964,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 964,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 964,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 964,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 964,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 965,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Builds a HTML input[type="range"] tag
    *
    * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 963,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 963,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 962,
          'last-line' => 969,
          'char' => 26,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 970,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 970,
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
                  'variable' => 'order',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 972,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'escaper',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 972,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'attrs',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 972,
                  'char' => 34,
                ),
                3 => 
                array (
                  'variable' => 'attribute',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 972,
                  'char' => 45,
                ),
                4 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 972,
                  'char' => 52,
                ),
                5 => 
                array (
                  'variable' => 'escaped',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 972,
                  'char' => 61,
                ),
                6 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 972,
                  'char' => 66,
                ),
                7 => 
                array (
                  'variable' => 'newCode',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 972,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 974,
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 975,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 975,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 975,
                        'char' => 26,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 976,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 976,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 976,
                        'char' => 26,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'for',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 977,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 977,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 977,
                        'char' => 26,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 978,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 978,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 978,
                        'char' => 26,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'href',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 979,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 979,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 979,
                        'char' => 26,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'action',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 980,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 980,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 980,
                        'char' => 26,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 981,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 981,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 981,
                        'char' => 26,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 982,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 982,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 982,
                        'char' => 26,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 983,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 983,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 983,
                        'char' => 26,
                      ),
                      9 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'class',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 984,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 985,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 985,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 985,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 985,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 987,
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
                  'variable' => 'attrs',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 987,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 987,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 989,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'order',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 989,
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
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attribute',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 990,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 990,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 990,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 990,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 990,
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
                          'operator' => 'assign',
                          'variable' => 'attrs',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 991,
                              'char' => 30,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attribute',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 991,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 991,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 992,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 993,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 995,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'attributes',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 995,
                'char' => 38,
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
                          'value' => 'attrs',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 996,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 996,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 996,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 996,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 996,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'attrs',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 997,
                              'char' => 30,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 997,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 997,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 998,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 999,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1001,
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
                  'variable' => 'escaper',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'EscaperInterface',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1001,
                      'char' => 70,
                    ),
                    'right' => 
                    array (
                      'type' => 'scall',
                      'dynamic-class' => 0,
                      'class' => 'self',
                      'dynamic' => 0,
                      'name' => 'getEscaper',
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attributes',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1001,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1001,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1001,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1001,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1001,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1003,
              'char' => 13,
            ),
            6 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'attrs',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1003,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'escape',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1003,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1003,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1005,
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
                  'variable' => 'newCode',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'code',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1005,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1005,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1007,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'attrs',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1007,
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1008,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1008,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1008,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1008,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1008,
                        'char' => 48,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1008,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1008,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1008,
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
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1009,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1009,
                                'char' => 44,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'array',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1009,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1009,
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
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1009,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1009,
                                'char' => 69,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'resource',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1009,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1009,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1009,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1009,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1009,
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
                                          'file' => '/app/phalcon/Tag.zep',
                                          'line' => 1011,
                                          'char' => 43,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'key',
                                          'file' => '/app/phalcon/Tag.zep',
                                          'line' => 1011,
                                          'char' => 49,
                                        ),
                                        'file' => '/app/phalcon/Tag.zep',
                                        'line' => 1011,
                                        'char' => 49,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\' type: \'',
                                        'file' => '/app/phalcon/Tag.zep',
                                        'line' => 1011,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Tag.zep',
                                      'line' => 1011,
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
                                            'file' => '/app/phalcon/Tag.zep',
                                            'line' => 1011,
                                            'char' => 76,
                                          ),
                                          'file' => '/app/phalcon/Tag.zep',
                                          'line' => 1011,
                                          'char' => 76,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Tag.zep',
                                      'line' => 1011,
                                      'char' => 78,
                                    ),
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 1011,
                                    'char' => 78,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\' cannot be rendered',
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 1012,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1012,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1012,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1012,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1013,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1015,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'escaper',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1015,
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
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1016,
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
                                      'file' => '/app/phalcon/Tag.zep',
                                      'line' => 1016,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 1016,
                                    'char' => 64,
                                  ),
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1016,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1016,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1017,
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
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1018,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1018,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1019,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1021,
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
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 1021,
                                    'char' => 33,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'key',
                                    'file' => '/app/phalcon/Tag.zep',
                                    'line' => 1021,
                                    'char' => 39,
                                  ),
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1021,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '=\\"',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1021,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1021,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'escaped',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1021,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1021,
                              'char' => 55,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\"',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1021,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1021,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1021,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1022,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1023,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1025,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'newCode',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1025,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1026,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders parameters keeping order in their HTML attributes
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 971,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 971,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 970,
          'last-line' => 1045,
          'char' => 26,
        ),
        33 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1046,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1046,
              'char' => 59,
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1046,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1046,
              'char' => 79,
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
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1048,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'scall',
                      'dynamic-class' => 0,
                      'class' => 'self',
                      'dynamic' => 0,
                      'name' => 'getTitle',
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'prepend',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1048,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1048,
                          'char' => 48,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'append',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1048,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1048,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1048,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1048,
                    'char' => 58,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => '</title>',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1048,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1048,
                  'char' => 69,
                ),
                'right' => 
                array (
                  'type' => 'constant',
                  'value' => 'PHP_EOL',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1048,
                  'char' => 78,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1048,
                'char' => 78,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1049,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders the title with title tags. The title is automaticall escaped
     *
     * ```php
     * Tag::prependTitle(\'Hello\');
     * Tag::setTitle(\'World\');
     * Tag::appendTitle(\'from Phalcon\');
     *
     * echo Tag::renderTitle();             // <title>Hello World from Phalcon</title>
     * echo Tag::renderTitle(false);        // <title>World from Phalcon</title>
     * echo Tag::renderTitle(true, false);  // <title>Hello World</title>
     * echo Tag::renderTitle(false, false); // <title>World</title>
     * ```
     *
     * ```php
     * {{ render_title() }}
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1047,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1047,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1046,
          'last-line' => 1056,
          'char' => 26,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'deprecated',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'resetInput',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'displayValues',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1059,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1059,
                  'char' => 37,
                ),
                1 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'documentTitle',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1060,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1060,
                  'char' => 39,
                ),
                2 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'documentAppendTitle',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1061,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1061,
                  'char' => 43,
                ),
                3 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'documentPrependTitle',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1062,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1062,
                  'char' => 44,
                ),
                4 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'documentTitleSeparator',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1063,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1063,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1064,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resets the request and internal values to avoid those fields will have
     * any default value.
     *
     * @deprecated Will be removed in 4.0.0
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1058,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1057,
          'last-line' => 1070,
          'char' => 37,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'searchField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1071,
              'char' => 54,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'search',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1073,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1073,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1073,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1073,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1073,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1074,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="search"] tag
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1072,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1072,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1071,
          'last-line' => 1096,
          'char' => 26,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'select',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1097,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1097,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1097,
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
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Select',
                'dynamic' => 0,
                'name' => 'selectField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1099,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1099,
                    'char' => 46,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1099,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1099,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1099,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1100,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML SELECT tag using a Phalcon\\Mvc\\Model resultset as options
     *
     *```php
     * echo Phalcon\\Tag::select(
     *     [
     *         "robotId",
     *         Robots::find("type = "mechanical""),
     *         "using" => ["id", "name"],
     *     ]
     * );
     *```
     *
     * Volt syntax:
     *```php
     * {{ select("robotId", robots, "using": ["id", "name"]) }}
     *```
     *
     * @param array parameters
     * @param array data
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1098,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1098,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1097,
          'last-line' => 1117,
          'char' => 26,
        ),
        37 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'selectStatic',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1118,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1118,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1118,
              'char' => 64,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Select',
                'dynamic' => 0,
                'name' => 'selectField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1120,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1120,
                    'char' => 46,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1120,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1120,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1120,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1121,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML SELECT tag using a PHP array for options
     *
     *```php
     * echo Phalcon\\Tag::selectStatic(
     *     "status",
     *     [
     *         "A" => "Active",
     *         "I" => "Inactive",
     *     ]
     * );
     *```
     *
     * @param array parameters
     * @param array data
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1119,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1119,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1118,
          'last-line' => 1125,
          'char' => 26,
        ),
        38 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setAutoescape',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'autoescape',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1126,
              'char' => 57,
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
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'autoEscape',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'autoescape',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1128,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1128,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set autoescape mode in generated html
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1127,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1126,
          'last-line' => 1143,
          'char' => 26,
        ),
        39 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setDefault',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1144,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1144,
              'char' => 56,
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
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1146,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1146,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1146,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1147,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1147,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1147,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1147,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1147,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1147,
                            'char' => 65,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1147,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1147,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1147,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1147,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1147,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1150,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1150,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1150,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1151,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1152,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1154,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'displayValues',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'id',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1154,
                      'char' => 35,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1154,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1154,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1155,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Assigns default values to generated tags by helpers
     *
     * ```php
     * // Assigning "peter" to "name" component
     * Phalcon\\Tag::setDefault("name", "peter");
     *
     * // Later in the view
     * echo Phalcon\\Tag::textField("name"); // Will have the value "peter" by default
     * ```
     *
     * @param string value
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1145,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1144,
          'last-line' => 1171,
          'char' => 26,
        ),
        40 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setDefaults',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1172,
              'char' => 53,
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1172,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1172,
              'char' => 73,
            ),
          ),
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
                  'type' => 'variable',
                  'value' => 'merge',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1174,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'static-property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1174,
                        'char' => 49,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'displayValues',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1174,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1174,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1174,
                    'char' => 49,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1174,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1174,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1174,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'displayValues',
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
                              'type' => 'static-property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'self',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1175,
                                'char' => 70,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'displayValues',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1175,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1175,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1175,
                            'char' => 70,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'values',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1175,
                              'char' => 78,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1175,
                            'char' => 78,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1175,
                        'char' => 79,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1175,
                      'char' => 79,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1176,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'displayValues',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'values',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1177,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1177,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1178,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1179,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Assigns default values to generated tags by helpers
     *
     * ```php
     * // Assigning "peter" to "name" component
     * Phalcon\\Tag::setDefaults(
     *     [
     *         "name" => "peter",
     *     ]
     * );
     *
     * // Later in the view
     * echo Phalcon\\Tag::textField("name"); // Will have the value "peter" by default
     * ```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1173,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1172,
          'last-line' => 1183,
          'char' => 26,
        ),
        41 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1184,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1184,
              'char' => 57,
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
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1186,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1186,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1187,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the dependency injector container.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1185,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1184,
          'last-line' => 1191,
          'char' => 26,
        ),
        42 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1192,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'less',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'doctype',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1194,
                    'char' => 20,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1194,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'HTML32',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1194,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1194,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1194,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'greater',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'doctype',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1194,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1194,
                      'char' => 61,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'XHTML5',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1194,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1194,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1194,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1194,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'documentType',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1195,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'HTML5',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1195,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1195,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1195,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1196,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => 'documentType',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'doctype',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1197,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1197,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1198,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1199,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the document type of content
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1193,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1192,
          'last-line' => 1207,
          'char' => 26,
        ),
        43 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1208,
              'char' => 49,
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
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'documentTitle',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'title',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1210,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1210,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1211,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the title of view content
     *
     *```php
     * Phalcon\\Tag::setTitle("Welcome to my Page");
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1209,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1208,
          'last-line' => 1219,
          'char' => 26,
        ),
        44 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setTitleSeparator',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'titleSeparator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1220,
              'char' => 67,
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
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'documentTitleSeparator',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'titleSeparator',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1222,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1222,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1223,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the title separator of view content
     *
     *```php
     * Phalcon\\Tag::setTitleSeparator("-");
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1221,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1220,
          'last-line' => 1244,
          'char' => 26,
        ),
        45 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'stylesheetLink',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1245,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1245,
              'char' => 64,
            ),
            1 => 
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1245,
                'char' => 83,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1245,
              'char' => 83,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1247,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1247,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1249,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1249,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1249,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1249,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1249,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1250,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1250,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'local',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1250,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1250,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1250,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1250,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1251,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1252,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1252,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1253,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1255,
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
                    'value' => 'params',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1255,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1255,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1255,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1255,
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
                      'variable' => 'local',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'bool',
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'params',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1256,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1256,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1256,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1256,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1256,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1257,
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
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1258,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'local',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1258,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1258,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1258,
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
                          'variable' => 'local',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'bool',
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'params',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1259,
                                'char' => 42,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'local',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1259,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1259,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1259,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1259,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1261,
                      'char' => 21,
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1261,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'local',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1261,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1261,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1262,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1263,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1265,
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1265,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1265,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1265,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1265,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1265,
                'char' => 32,
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
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1266,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'text/css',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1266,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1266,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1267,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1269,
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1269,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'href',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1269,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1269,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1269,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1269,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
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
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1270,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1270,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1270,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1270,
                    'char' => 32,
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
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'href',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1271,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1271,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1271,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1271,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1271,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1272,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'href',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1273,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1273,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1273,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1274,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1275,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1280,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'local',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1280,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'href',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1281,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'self',
                          'dynamic' => 0,
                          'name' => 'getUrlService',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1281,
                          'char' => 54,
                        ),
                        'name' => 'getStatic',
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
                                'value' => 'params',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1282,
                                'char' => 23,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'href',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1282,
                                'char' => 28,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1283,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1283,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1283,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1283,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1284,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1286,
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1286,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'rel',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1286,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1286,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1286,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1286,
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
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'rel',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1287,
                          'char' => 27,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'stylesheet',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1287,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1287,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1288,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1290,
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
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '<link',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1290,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1290,
                        'char' => 48,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1290,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1290,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1290,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1290,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1295,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1295,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'documentType',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1295,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1295,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1295,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'HTML5',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1295,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1295,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1295,
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
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' />',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1296,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1296,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1296,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1296,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1297,
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
                      'operator' => 'concat-assign',
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '>',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1298,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1298,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1298,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1298,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1299,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1301,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1301,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1302,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a LINK[rel="stylesheet"] tag
     *
     * ```php
     * echo Phalcon\\Tag::stylesheetLink(
     *     "http://fonts.googleapis.com/css?family=Rosario",
     *     false
     * );
     *
     * echo Phalcon\\Tag::stylesheetLink("css/style.css");
     * ```
     *
     * Volt Syntax:
     *```php
     * {{ stylesheet_link("http://fonts.googleapis.com/css?family=Rosario", false) }}
     * {{ stylesheet_link("css/style.css") }}
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1246,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1246,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1245,
          'last-line' => 1317,
          'char' => 26,
        ),
        46 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'submitButton',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1318,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'submit',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1320,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1320,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1320,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1320,
                    'char' => 51,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1320,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1320,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1320,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1321,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="submit"] tag
     *
     *```php
     * echo Phalcon\\Tag::submitButton("Save")
     *```
     *
     * Volt syntax:
     *```php
     * {{ submit_button("Save") }}
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1319,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1319,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1318,
          'last-line' => 1325,
          'char' => 26,
        ),
        47 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'tagHtml',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tagName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1327,
              'char' => 23,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1328,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1328,
              'char' => 30,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'selfClose',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1329,
                'char' => 31,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1329,
              'char' => 31,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'onlyStart',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1330,
                'char' => 31,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1330,
              'char' => 31,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'useEol',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1332,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1332,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1334,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'localCode',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1334,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1336,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1336,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1336,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1336,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1336,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1337,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1337,
                            'char' => 37,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1337,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1337,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1338,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1339,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1339,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1340,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1342,
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
                  'variable' => 'localCode',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
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
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1342,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tagName',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1342,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1342,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1342,
                        'char' => 59,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1342,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1342,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1342,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1342,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1347,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1347,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'documentType',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1347,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1347,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1347,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'HTML5',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1347,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1347,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1347,
                'char' => 45,
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
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1348,
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
                          'variable' => 'localCode',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => ' />',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1349,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1349,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1350,
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
                          'variable' => 'localCode',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '>',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1351,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1351,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1352,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1353,
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
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1354,
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
                          'variable' => 'localCode',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '>',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1355,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1355,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1356,
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
                          'variable' => 'localCode',
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
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1357,
                                'char' => 37,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'tagName',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1357,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1357,
                              'char' => 47,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '>',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1357,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1357,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1357,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1358,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1359,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1361,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'useEol',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1361,
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
                      'variable' => 'localCode',
                      'expr' => 
                      array (
                        'type' => 'constant',
                        'value' => 'PHP_EOL',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1362,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1362,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1363,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1365,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'localCode',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1365,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1366,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML tag
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1333,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1333,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1326,
          'last-line' => 1374,
          'char' => 26,
        ),
        48 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'tagHtmlClose',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tagName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1375,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'useEol',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1375,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1375,
              'char' => 76,
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
                'value' => 'useEol',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1377,
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
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1378,
                          'char' => 23,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'tagName',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1378,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1378,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '>',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1378,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1378,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'PHP_EOL',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1378,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1378,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1379,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1381,
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
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '</',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1381,
                    'char' => 19,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tagName',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1381,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1381,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '>',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1381,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1381,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1382,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML tag closing tag
     *
     *```php
     * echo Phalcon\\Tag::tagHtmlClose("script", true);
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1376,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1376,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1375,
          'last-line' => 1388,
          'char' => 26,
        ),
        49 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'telField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1389,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'tel',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1391,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1391,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1391,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1391,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1391,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1392,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Builds a HTML input[type="tel"] tag
    *
    * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1390,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1390,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1389,
          'last-line' => 1413,
          'char' => 26,
        ),
        50 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'textArea',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1414,
              'char' => 51,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1416,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'id',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1416,
                  'char' => 23,
                ),
                2 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1416,
                  'char' => 29,
                ),
                3 => 
                array (
                  'variable' => 'content',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1416,
                  'char' => 38,
                ),
                4 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1416,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1418,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1418,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1418,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1418,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1418,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1419,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1419,
                            'char' => 37,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1419,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1419,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1420,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1421,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1421,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1422,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1424,
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
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1424,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1424,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1424,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1424,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1424,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
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
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1425,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1425,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1425,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1425,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1426,
                              'char' => 29,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1426,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1426,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1426,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1426,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1427,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1428,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1430,
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
                  'variable' => 'id',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1430,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1430,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1430,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1430,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1432,
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1432,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1432,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1432,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1432,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1432,
                'char' => 32,
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
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1433,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1433,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1433,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1434,
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
                      'variable' => 'name',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1435,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1435,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1435,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1435,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1437,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1437,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1437,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'name',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1438,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1438,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1438,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1439,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1440,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1442,
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
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1442,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'id',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1442,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1442,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1442,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1442,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1443,
                          'char' => 26,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1443,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1443,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1444,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1446,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'params',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1446,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'value',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1446,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1446,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1446,
                'char' => 32,
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1447,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1447,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1447,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1447,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1449,
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
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1449,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1449,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1449,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1450,
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
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'getValue',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1451,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1451,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1451,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1451,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1451,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1451,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1452,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1454,
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
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '<textarea',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1454,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1454,
                        'char' => 52,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1454,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1454,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1454,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1454,
                  'char' => 61,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '>',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1455,
                        'char' => 22,
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
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1455,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1455,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1455,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1455,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</textarea>',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1455,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1455,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1455,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1457,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1457,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1458,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML TEXTAREA tag
     *
     *```php
     * echo Phalcon\\Tag::textArea(
     *     [
     *         "comments",
     *         "cols" => 10,
     *         "rows" => 4,
     *     ]
     * );
     *```
     *
     * Volt syntax:
     *```php
     * {{ text_area("comments", "cols": 10, "rows": 4) }}
     *```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1415,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1415,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1414,
          'last-line' => 1473,
          'char' => 26,
        ),
        51 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'textField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1474,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'text',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1476,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1476,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1476,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1476,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1476,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1477,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="text"] tag
     *
     * ```php
     * echo Phalcon\\Tag::textField(
     *     [
     *         "name",
     *         "size" => 30,
     *     ]
     * );
     * ```
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1475,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1475,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1474,
          'last-line' => 1483,
          'char' => 26,
        ),
        52 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'timeField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1484,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'time',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1486,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1486,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1486,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1486,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1486,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1487,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="time"] tag
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1485,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1485,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1484,
          'last-line' => 1493,
          'char' => 26,
        ),
        53 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'urlField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1494,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'url',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1496,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1496,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1496,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1496,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1496,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1497,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="url"] tag
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1495,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1495,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1494,
          'last-line' => 1503,
          'char' => 26,
        ),
        54 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'weekField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1504,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'inputField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'week',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1506,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1506,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1506,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1506,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1506,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1507,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="week"] tag
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1505,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1505,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1504,
          'last-line' => 1513,
          'char' => 26,
        ),
        55 => 
        array (
          'visibility' => 
          array (
            0 => 'static',
            1 => 'final',
            2 => 'protected',
          ),
          'type' => 'method',
          'name' => 'inputField',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1514,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1514,
              'char' => 71,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'asValue',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1514,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1514,
              'char' => 93,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1516,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'id',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1516,
                  'char' => 23,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1516,
                  'char' => 30,
                ),
                3 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1516,
                  'char' => 36,
                ),
                4 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1516,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1518,
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
                  'variable' => 'params',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1518,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1518,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1520,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1520,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1520,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1520,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1520,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1521,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1521,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1522,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1523,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1523,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1524,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1526,
              'char' => 10,
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
                  'value' => 'asValue',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1526,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1526,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1526,
                'char' => 29,
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
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1527,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1527,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1527,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1527,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1527,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1527,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1528,
                              'char' => 29,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1528,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1528,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1528,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1528,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1529,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1531,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1531,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1531,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'name',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1531,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1531,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1531,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1532,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1532,
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
                              'variable' => 'params',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1533,
                                  'char' => 36,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'id',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1533,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1533,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1534,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1535,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'name',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1536,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1536,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1536,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1537,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1542,
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
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1542,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1542,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1542,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1542,
                    'char' => 36,
                  ),
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
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'memstr',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'id',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1543,
                                  'char' => 30,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1543,
                                'char' => 30,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '[',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1543,
                                  'char' => 33,
                                ),
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1543,
                                'char' => 33,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1543,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1543,
                          'char' => 36,
                        ),
                        'right' => 
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
                                'value' => 'params',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1543,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'id',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1543,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1543,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1543,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1543,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1543,
                        'char' => 56,
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
                              'variable' => 'params',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'id',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1544,
                                  'char' => 34,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'id',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1544,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1544,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1545,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1546,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1548,
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
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1548,
                          'char' => 29,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'getValue',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1548,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1548,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1548,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1548,
                            'char' => 58,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1548,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1548,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1549,
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1553,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1553,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1553,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1553,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1553,
                    'char' => 37,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1554,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'params',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1554,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1554,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1554,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1554,
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
                              'variable' => 'params',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Tag.zep',
                                  'line' => 1555,
                                  'char' => 37,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Tag.zep',
                                'line' => 1555,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1555,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1556,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1557,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1558,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1560,
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
                  'variable' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1560,
                      'char' => 24,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1560,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1560,
                  'char' => 32,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '<input',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1561,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1561,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1561,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1561,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1561,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1561,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1566,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1566,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'documentType',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1566,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1566,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1566,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'HTML5',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1566,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1566,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1566,
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
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => ' />',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1567,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1567,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1568,
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
                      'operator' => 'concat-assign',
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '>',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1569,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1569,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1570,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1572,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1572,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1573,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds generic INPUT tags
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1515,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1515,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1514,
          'last-line' => 1579,
          'char' => 35,
        ),
        56 => 
        array (
          'visibility' => 
          array (
            0 => 'static',
            1 => 'final',
            2 => 'protected',
          ),
          'type' => 'method',
          'name' => 'inputFieldChecked',
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
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1580,
              'char' => 66,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1580,
              'char' => 82,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1582,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1582,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'id',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1582,
                  'char' => 30,
                ),
                3 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1582,
                  'char' => 36,
                ),
                4 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1582,
                  'char' => 42,
                ),
                5 => 
                array (
                  'variable' => 'currentValue',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1582,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1584,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1584,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1584,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1584,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1584,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1585,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1585,
                            'char' => 37,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1585,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1585,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1586,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1587,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1587,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1588,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1590,
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
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1590,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1590,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1590,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1590,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1590,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1591,
                          'char' => 25,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1591,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1591,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1591,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1591,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1592,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1594,
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
                  'variable' => 'id',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1594,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1594,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1594,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1594,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1596,
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1596,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1596,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1596,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1596,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1596,
                'char' => 32,
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
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1597,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1597,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1597,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1598,
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
                      'variable' => 'name',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1599,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1599,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1599,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1599,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1601,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1601,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1601,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'name',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1602,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1602,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1602,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1603,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1604,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1609,
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
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1609,
                        'char' => 22,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1609,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '[',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1609,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1609,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1609,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1609,
                'char' => 27,
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1610,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1610,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1610,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1610,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1610,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1611,
                              'char' => 30,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1611,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1611,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1612,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1613,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1618,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'currentValue',
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1618,
                  'char' => 46,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1618,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'value',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1618,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1618,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1618,
                'char' => 46,
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
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1619,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1619,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1619,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1621,
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
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'getValue',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1621,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1621,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1621,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1621,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1621,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1621,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1623,
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
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1623,
                        'char' => 23,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1623,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1623,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'currentValue',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1623,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1623,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1623,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1623,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'checked',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1624,
                              'char' => 35,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'checked',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1624,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1624,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1625,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1627,
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
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1627,
                          'char' => 29,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'currentValue',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1627,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1627,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1628,
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
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'getValue',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1629,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1629,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1629,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1629,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1629,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1629,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1634,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1634,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1634,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1634,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'checked',
                              'file' => '/app/phalcon/Tag.zep',
                              'line' => 1635,
                              'char' => 35,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'checked',
                            'file' => '/app/phalcon/Tag.zep',
                            'line' => 1635,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1635,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1636,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1641,
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
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1641,
                          'char' => 29,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1641,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1641,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1642,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1644,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1644,
                      'char' => 24,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1644,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1644,
                  'char' => 32,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'renderAttributes',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '<input',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1645,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1645,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag.zep',
                          'line' => 1645,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1645,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1645,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1645,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1650,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1650,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'documentType',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1650,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1650,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1650,
                    'char' => 45,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'HTML5',
                    'file' => '/app/phalcon/Tag.zep',
                    'line' => 1650,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1650,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1650,
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
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => ' />',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1651,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1651,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1652,
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
                      'operator' => 'concat-assign',
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '>',
                        'file' => '/app/phalcon/Tag.zep',
                        'line' => 1653,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Tag.zep',
                      'line' => 1653,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag.zep',
                  'line' => 1654,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1656,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1656,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag.zep',
              'line' => 1657,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds INPUT tags that implements the checked attribute
     *
     * @param array parameters
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
                'file' => '/app/phalcon/Tag.zep',
                'line' => 1581,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag.zep',
            'line' => 1581,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 1580,
          'last-line' => 1658,
          'char' => 35,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 24,
            'char' => 21,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 25,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 25,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 26,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 26,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 27,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 27,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 28,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 28,
            'char' => 20,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 29,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 29,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 30,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 30,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 31,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 31,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 32,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 32,
            'char' => 22,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 33,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 33,
            'char' => 23,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 34,
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
            'file' => '/app/phalcon/Tag.zep',
            'line' => 34,
            'char' => 22,
          ),
          'file' => '/app/phalcon/Tag.zep',
          'line' => 36,
          'char' => 13,
        ),
      ),
      'file' => '/app/phalcon/Tag.zep',
      'line' => 22,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Tag.zep',
    'line' => 22,
    'char' => 5,
  ),
);