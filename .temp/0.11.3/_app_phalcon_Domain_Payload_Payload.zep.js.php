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
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 *',
    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
    'line' => 19,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Domain\\Payload',
    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
    'line' => 21,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Domain\\Payload\\PayloadInterface',
        'file' => '/app/phalcon/Domain/Payload/Payload.zep',
        'line' => 21,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
    'line' => 25,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Holds the payload
 *',
    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
    'line' => 26,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Payload',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'PayloadInterface',
        'file' => '/app/phalcon/Domain/Payload/Payload.zep',
        'line' => 27,
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
          'name' => 'extras',
          'docblock' => '**
     * Extra information
     *
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 33,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 39,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'input',
          'docblock' => '**
     * Input
     *
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 40,
              'char' => 27,
            ),
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 46,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'messages',
          'docblock' => '**
     * Messages
     *
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 47,
              'char' => 30,
            ),
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 53,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'status',
          'docblock' => '**
     * Status
     *
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 54,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 60,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'output',
          'docblock' => '**
     * Output
     *
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 61,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 65,
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
          'name' => 'setExtras',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'extras',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 66,
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
                  'property' => 'extras',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'extras',
                    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                    'line' => 68,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 68,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 70,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 70,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 71,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets arbitrary extra domain information.
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
                  'value' => 'PayloadInterface',
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 67,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/Payload.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 66,
          'last-line' => 75,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setInput',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'input',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 76,
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
                  'property' => 'input',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'input',
                    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                    'line' => 78,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 78,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 80,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 80,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the domain input.
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
                  'value' => 'PayloadInterface',
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 77,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 77,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/Payload.zep',
            'line' => 77,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 76,
          'last-line' => 85,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setMessages',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'messages',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 86,
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
                  'property' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'messages',
                    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                    'line' => 88,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 88,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 90,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 90,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 91,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the domain messages.
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
                  'value' => 'PayloadInterface',
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 87,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 87,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/Payload.zep',
            'line' => 87,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 86,
          'last-line' => 95,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setOutput',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'output',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 96,
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
                  'property' => 'output',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'output',
                    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                    'line' => 98,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 98,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 100,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 100,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 101,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the domain output.
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
                  'value' => 'PayloadInterface',
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 97,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 97,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/Payload.zep',
            'line' => 97,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 96,
          'last-line' => 105,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setStatus',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'status',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 106,
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
                  'property' => 'status',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'status',
                    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                    'line' => 108,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 108,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 110,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 110,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Domain/Payload/Payload.zep',
              'line' => 111,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the payload status.
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
                  'value' => 'PayloadInterface',
                  'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                  'line' => 107,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/Payload.zep',
                'line' => 107,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/Payload.zep',
            'line' => 107,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Domain/Payload/Payload.zep',
          'line' => 106,
          'last-line' => 112,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Domain/Payload/Payload.zep',
      'line' => 26,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Domain/Payload/Payload.zep',
    'line' => 26,
    'char' => 5,
  ),
);