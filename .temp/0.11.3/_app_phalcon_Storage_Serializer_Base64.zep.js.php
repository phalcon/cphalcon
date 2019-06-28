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
    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Serializer',
    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
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
        'name' => 'InvalidArgumentException',
        'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
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
        'name' => 'Phalcon\\Storage\\Serializer\\AbstractSerializer',
        'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
        'line' => 14,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
    'line' => 16,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Base64',
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
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                      'line' => 23,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                      'line' => 23,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                    'line' => 23,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                  'line' => 23,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                  'line' => 23,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                'line' => 23,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Data for the serializer must of type string',
                          'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                          'line' => 26,
                          'char' => 10,
                        ),
                        'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                        'line' => 26,
                        'char' => 10,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                    'line' => 26,
                    'char' => 11,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                  'line' => 27,
                  'char' => 6,
                ),
              ),
              'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
              'line' => 29,
              'char' => 8,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'base64_encode',
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
                        'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                        'line' => 29,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                        'line' => 29,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                      'line' => 29,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                    'line' => 29,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                'line' => 29,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
              'line' => 30,
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
                'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                'line' => 22,
                'char' => 2,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
            'line' => 22,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
          'line' => 21,
          'last-line' => 34,
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
              'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
              'line' => 35,
              'char' => 38,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                    'line' => 37,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                  'line' => 37,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                  'line' => 37,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                'line' => 37,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Data for the unserializer must of type string',
                          'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                          'line' => 40,
                          'char' => 10,
                        ),
                        'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                        'line' => 40,
                        'char' => 10,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                    'line' => 40,
                    'char' => 11,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                  'line' => 41,
                  'char' => 6,
                ),
              ),
              'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
              'line' => 43,
              'char' => 5,
            ),
            1 => 
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
                    'name' => 'base64_decode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                          'line' => 43,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                        'line' => 43,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                    'line' => 43,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
                  'line' => 43,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
              'line' => 44,
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
            'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
            'line' => 36,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
          'line' => 35,
          'last-line' => 45,
          'char' => 16,
        ),
      ),
      'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
      'line' => 16,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/Serializer/Base64.zep',
    'line' => 16,
    'char' => 5,
  ),
);