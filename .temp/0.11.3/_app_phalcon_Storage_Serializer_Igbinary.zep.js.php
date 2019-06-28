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
    'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Serializer',
    'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
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
        'name' => 'Phalcon\\Storage\\Serializer\\AbstractSerializer',
        'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
        'line' => 13,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
    'line' => 15,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Igbinary',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractSerializer',
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
          'name' => 'serialize',
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
                  'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                  'line' => 22,
                  'char' => 17,
                ),
                'name' => 'isSerializable',
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
                        'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                        'line' => 22,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                        'line' => 22,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                      'line' => 22,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                    'line' => 22,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                'line' => 22,
                'char' => 45,
              ),
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
                      'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                      'line' => 23,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                      'line' => 23,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                    'line' => 23,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                  'line' => 24,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
              'line' => 26,
              'char' => 8,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'igbinary_serialize',
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
                        'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                        'line' => 26,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                        'line' => 26,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                      'line' => 26,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                    'line' => 26,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                'line' => 26,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
              'line' => 27,
              'char' => 2,
            ),
          ),
          'docblock' => '**
	 * Serializes data
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
                'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                'line' => 21,
                'char' => 2,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
            'line' => 21,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
          'line' => 20,
          'last-line' => 31,
          'char' => 16,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'unserialize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
              'line' => 32,
              'char' => 38,
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
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'igbinary_unserialize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                          'line' => 34,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                        'line' => 34,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                    'line' => 34,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
                  'line' => 34,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
              'line' => 35,
              'char' => 2,
            ),
          ),
          'docblock' => '**
	 * Unserializes data
	 *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
            'line' => 33,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
          'line' => 32,
          'last-line' => 36,
          'char' => 16,
        ),
      ),
      'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
      'line' => 15,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/Serializer/Igbinary.zep',
    'line' => 15,
    'char' => 5,
  ),
);