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
    'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Serializer',
    'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
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
        'name' => 'Phalcon\\Storage\\Exception',
        'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
        'line' => 13,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
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
        'name' => 'Phalcon\\Storage\\Serializer\\SerializerInterface',
        'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
        'line' => 14,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
    'line' => 16,
    'char' => 8,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'AbstractSerializer',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'SerializerInterface',
        'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
        'line' => 17,
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
          'name' => 'data',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
            'line' => 21,
            'char' => 27,
          ),
          'docblock' => '**
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
              'line' => 21,
              'char' => 32,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
              'line' => 21,
              'char' => 38,
            ),
          ),
          'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
          'line' => 25,
          'char' => 3,
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
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                'line' => 26,
                'char' => 45,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
              'line' => 26,
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
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                    'line' => 28,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                  'line' => 28,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
              'line' => 29,
              'char' => 2,
            ),
          ),
          'docblock' => '**
	 * Constructor
	 *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
            'line' => 27,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
          'line' => 26,
          'last-line' => 33,
          'char' => 16,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'isSerializable',
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
              'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
              'line' => 34,
              'char' => 44,
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
                  'type' => 'or',
                  'left' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                      'line' => 36,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                    'line' => 36,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                        'line' => 36,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                      'line' => 36,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'bool',
                      'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                      'line' => 36,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                    'line' => 36,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                  'line' => 36,
                  'char' => 52,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_numeric',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                        'line' => 36,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                      'line' => 36,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                  'line' => 36,
                  'char' => 70,
                ),
                'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                'line' => 36,
                'char' => 70,
              ),
              'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
              'line' => 37,
              'char' => 2,
            ),
          ),
          'docblock' => '**
     * If this returns true, then the data returns back as is
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
                'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
                'line' => 35,
                'char' => 2,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
            'line' => 35,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
          'line' => 34,
          'last-line' => 38,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
      'line' => 16,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Storage/Serializer/AbstractSerializer.zep',
    'line' => 16,
    'char' => 14,
  ),
);