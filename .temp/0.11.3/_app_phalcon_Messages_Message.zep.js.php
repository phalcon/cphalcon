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
    'file' => '/app/phalcon/Messages/Message.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Messages',
    'file' => '/app/phalcon/Messages/Message.zep',
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
        'name' => 'JsonSerializable',
        'file' => '/app/phalcon/Messages/Message.zep',
        'line' => 13,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Messages/Message.zep',
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
        'name' => 'Phalcon\\Messages\\MessageInterface',
        'file' => '/app/phalcon/Messages/Message.zep',
        'line' => 14,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Messages/Message.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Messages\\Message
 *
 * Stores a message from various components
 *',
    'file' => '/app/phalcon/Messages/Message.zep',
    'line' => 21,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Message',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'MessageInterface',
        'file' => '/app/phalcon/Messages/Message.zep',
        'line' => 21,
        'char' => 42,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'JsonSerializable',
        'file' => '/app/phalcon/Messages/Message.zep',
        'line' => 22,
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
          'name' => 'code',
          'docblock' => '**
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 26,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 30,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'field',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 31,
              'char' => 27,
            ),
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 35,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'message',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 36,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 40,
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
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 41,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 45,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'metaData',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 46,
            'char' => 29,
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
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 46,
              'char' => 35,
            ),
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 50,
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
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 51,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 51,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 51,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 51,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 51,
              'char' => 78,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 51,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 51,
              'char' => 92,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'metaData',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 51,
                'char' => 113,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 51,
              'char' => 113,
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
                  'property' => 'message',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'message',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 53,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 53,
                  'char' => 37,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'field',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'field',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 54,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 54,
                  'char' => 35,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 55,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 55,
                  'char' => 34,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'code',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'code',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 56,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 56,
                  'char' => 34,
                ),
                4 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'metaData',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'metaData',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 57,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 57,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 58,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Messages\\Message constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 52,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 51,
          'last-line' => 62,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__toString',
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
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 65,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'message',
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 65,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 65,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 66,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic __toString method returns verbose message
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
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 64,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 64,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 63,
          'last-line' => 70,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => '__set_state',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 71,
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
                'type' => 'new',
                'class' => 'self',
                'dynamic' => 0,
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
                        'value' => 'message',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 74,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '_message',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 74,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 74,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 74,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 75,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '_field',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 75,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 75,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 75,
                    'char' => 28,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 76,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '_type',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 76,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 76,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 76,
                    'char' => 27,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 77,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '_code',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 77,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 77,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 77,
                    'char' => 27,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 78,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '_metaData',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 78,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 79,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 79,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 79,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 80,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic __set_state helps to re-build messages variable exporting
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
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 72,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 72,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 72,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 71,
          'last-line' => 84,
          'char' => 26,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'jsonSerialize',
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
                      'value' => 'field',
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 88,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 88,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 88,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 88,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 88,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'message',
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 89,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 89,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 89,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 89,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 89,
                    'char' => 37,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 90,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 90,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 90,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 90,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 90,
                    'char' => 34,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'code',
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 91,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 91,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'code',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 91,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 91,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 91,
                    'char' => 34,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'metaData',
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 92,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 92,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'metaData',
                        'file' => '/app/phalcon/Messages/Message.zep',
                        'line' => 93,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Messages/Message.zep',
                      'line' => 93,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 93,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 93,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 94,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Serializes the object for json_encode
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
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 86,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 86,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 85,
          'last-line' => 98,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setCode',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 99,
              'char' => 37,
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
                  'property' => 'code',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'code',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 101,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 101,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 103,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 103,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 104,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets code for the message
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
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 100,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 100,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 100,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 99,
          'last-line' => 108,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 109,
              'char' => 39,
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
                  'property' => 'field',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'field',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 111,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 111,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 113,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 113,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 114,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets field name related to message
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
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 110,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 110,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 110,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 109,
          'last-line' => 118,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setMessage',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 119,
              'char' => 47,
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
                  'property' => 'message',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'message',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 121,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 121,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 123,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 123,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 124,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets verbose message
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
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 120,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 120,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 120,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 119,
          'last-line' => 128,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setMetaData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'metaData',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 129,
              'char' => 48,
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
                  'property' => 'metaData',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'metaData',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 131,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 131,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 133,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 133,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 134,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets message metadata
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
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 130,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 130,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 130,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 129,
          'last-line' => 138,
          'char' => 19,
        ),
        8 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 139,
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
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Messages/Message.zep',
                    'line' => 141,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 141,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 143,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 143,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Messages/Message.zep',
              'line' => 144,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets message type
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
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Messages/Message.zep',
                  'line' => 140,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/Message.zep',
                'line' => 140,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Message.zep',
            'line' => 140,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Message.zep',
          'line' => 139,
          'last-line' => 145,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Messages/Message.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Messages/Message.zep',
    'line' => 21,
    'char' => 5,
  ),
);