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
    'file' => '/app/phalcon/Messages/MessageInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Messages',
    'file' => '/app/phalcon/Messages/MessageInterface.zep',
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
        'name' => 'Phalcon\\Messages\\Message',
        'file' => '/app/phalcon/Messages/MessageInterface.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Messages/MessageInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Messages\\MessageInterface
 *
 * Interface for Phalcon\\Messages\\MessageInterface
 *',
    'file' => '/app/phalcon/Messages/MessageInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'MessageInterface',
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
          'name' => '__toString',
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
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 25,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 25,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 25,
          'last-line' => 31,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCode',
          'docblock' => '**
     * Returns the message code related to this message
     *
     * @return int
     *',
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 32,
          'last-line' => 38,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getField',
          'docblock' => '**
     * Returns field name related to message
     *
     * @return string
     *',
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 39,
          'last-line' => 43,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessage',
          'docblock' => '**
     * Returns verbose message
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
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 44,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 44,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 44,
          'last-line' => 48,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMetaData',
          'docblock' => '**
     * Returns message metadata
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
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 49,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 49,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 49,
          'last-line' => 53,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getType',
          'docblock' => '**
     * Returns message type
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
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 54,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 54,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 54,
          'last-line' => 58,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Messages/MessageInterface.zep',
              'line' => 59,
              'char' => 37,
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
                  'file' => '/app/phalcon/Messages/MessageInterface.zep',
                  'line' => 59,
                  'char' => 60,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 59,
                'char' => 60,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 59,
            'char' => 60,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 59,
          'last-line' => 63,
          'char' => 19,
        ),
        7 => 
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
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/MessageInterface.zep',
              'line' => 64,
              'char' => 43,
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
                  'file' => '/app/phalcon/Messages/MessageInterface.zep',
                  'line' => 64,
                  'char' => 66,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 64,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 64,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 64,
          'last-line' => 68,
          'char' => 19,
        ),
        8 => 
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
              'file' => '/app/phalcon/Messages/MessageInterface.zep',
              'line' => 69,
              'char' => 47,
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
                  'file' => '/app/phalcon/Messages/MessageInterface.zep',
                  'line' => 69,
                  'char' => 70,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 69,
                'char' => 70,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 69,
            'char' => 70,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 69,
          'last-line' => 73,
          'char' => 19,
        ),
        9 => 
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
              'file' => '/app/phalcon/Messages/MessageInterface.zep',
              'line' => 74,
              'char' => 48,
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
                  'file' => '/app/phalcon/Messages/MessageInterface.zep',
                  'line' => 74,
                  'char' => 71,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 74,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 74,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 74,
          'last-line' => 78,
          'char' => 19,
        ),
        10 => 
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
              'file' => '/app/phalcon/Messages/MessageInterface.zep',
              'line' => 79,
              'char' => 41,
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
                  'file' => '/app/phalcon/Messages/MessageInterface.zep',
                  'line' => 79,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/MessageInterface.zep',
                'line' => 79,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/MessageInterface.zep',
            'line' => 79,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Messages/MessageInterface.zep',
          'line' => 79,
          'last-line' => 80,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Messages/MessageInterface.zep',
      'line' => 80,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Messages/MessageInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);