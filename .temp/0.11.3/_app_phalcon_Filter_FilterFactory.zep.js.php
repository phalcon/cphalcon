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
    'file' => '/app/phalcon/Filter/FilterFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter',
    'file' => '/app/phalcon/Filter/FilterFactory.zep',
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
        'name' => 'Phalcon\\Filter\\Filter',
        'file' => '/app/phalcon/Filter/FilterFactory.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Filter/FilterFactory.zep',
    'line' => 15,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'FilterFactory',
    'abstract' => 0,
    'final' => 0,
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
          'name' => 'newInstance',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Filter',
                'dynamic' => 0,
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
                        'file' => '/app/phalcon/Filter/FilterFactory.zep',
                        'line' => 24,
                        'char' => 18,
                      ),
                      'name' => 'getAdapters',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 25,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 25,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Filter/FilterFactory.zep',
                'line' => 25,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Filter/FilterFactory.zep',
              'line' => 26,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a Locator object with all the helpers defined in anonynous
     * functions
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
                  'value' => 'LocatorInterface',
                  'file' => '/app/phalcon/Filter/FilterFactory.zep',
                  'line' => 22,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Filter/FilterFactory.zep',
                'line' => 22,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Filter/FilterFactory.zep',
            'line' => 22,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/FilterFactory.zep',
          'line' => 21,
          'last-line' => 28,
          'char' => 19,
        ),
        1 => 
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
                      'value' => 'absint',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 31,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\AbsInt',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 31,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 31,
                    'char' => 62,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'alnum',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 32,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Alnum',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 32,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 32,
                    'char' => 61,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'alpha',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 33,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Alpha',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 33,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 33,
                    'char' => 61,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'bool',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 34,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\BoolVal',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 34,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 34,
                    'char' => 63,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'email',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 35,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Email',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 35,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 35,
                    'char' => 61,
                  ),
                  5 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'float',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 36,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\FloatVal',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 36,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 36,
                    'char' => 64,
                  ),
                  6 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'int',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 37,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\IntVal',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 37,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 37,
                    'char' => 62,
                  ),
                  7 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'lower',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 38,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Lower',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 38,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 38,
                    'char' => 61,
                  ),
                  8 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'lowerFirst',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 39,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\LowerFirst',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 39,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 39,
                    'char' => 66,
                  ),
                  9 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'regex',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 40,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Regex',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 40,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 40,
                    'char' => 61,
                  ),
                  10 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'remove',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 41,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Remove',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 41,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 41,
                    'char' => 62,
                  ),
                  11 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'replace',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 42,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Replace',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 42,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 42,
                    'char' => 63,
                  ),
                  12 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'special',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 43,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Special',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 43,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 43,
                    'char' => 63,
                  ),
                  13 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'specialFull',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 44,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\SpecialFull',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 44,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 44,
                    'char' => 67,
                  ),
                  14 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 45,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\StringVal',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 45,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 45,
                    'char' => 65,
                  ),
                  15 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'striptags',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 46,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Striptags',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 46,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 46,
                    'char' => 65,
                  ),
                  16 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'trim',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 47,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Trim',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 47,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 47,
                    'char' => 60,
                  ),
                  17 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'upper',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 48,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Upper',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 48,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 48,
                    'char' => 61,
                  ),
                  18 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'upperFirst',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 49,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\UpperFirst',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 49,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 49,
                    'char' => 66,
                  ),
                  19 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'upperWords',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 50,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\UpperWords',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 50,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 50,
                    'char' => 66,
                  ),
                  20 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'url',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 51,
                      'char' => 25,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Url',
                      'file' => '/app/phalcon/Filter/FilterFactory.zep',
                      'line' => 52,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Filter/FilterFactory.zep',
                    'line' => 52,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Filter/FilterFactory.zep',
                'line' => 52,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Filter/FilterFactory.zep',
              'line' => 53,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Filter/FilterFactory.zep',
                'line' => 29,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Filter/FilterFactory.zep',
            'line' => 29,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/FilterFactory.zep',
          'line' => 28,
          'last-line' => 54,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Filter/FilterFactory.zep',
      'line' => 15,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/FilterFactory.zep',
    'line' => 15,
    'char' => 5,
  ),
);