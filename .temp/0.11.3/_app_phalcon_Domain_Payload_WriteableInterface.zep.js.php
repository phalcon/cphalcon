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
    'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Domain\\Payload',
    'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
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
        'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
        'line' => 21,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
    'line' => 25,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This interface is used for consumers (write)
 *',
    'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
    'line' => 26,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'WriteableInterface',
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
              'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
              'line' => 33,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets the status of this payload.
     *
     * @param mixed $status The status for this payload.
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
                  'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                  'line' => 33,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                'line' => 33,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
            'line' => 33,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
          'line' => 33,
          'last-line' => 41,
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
              'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
              'line' => 42,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     *
     * Sets the input received by the domain layer.
     *
     * @param mixed $input The input received by the domain layer.
     *
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
                  'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                  'line' => 42,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                'line' => 42,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
            'line' => 42,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
          'line' => 42,
          'last-line' => 48,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
              'line' => 49,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets the output produced from the domain layer.
     *
     * @param mixed $output The output produced from the domain layer.
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
                  'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                  'line' => 49,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                'line' => 49,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
            'line' => 49,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
          'line' => 49,
          'last-line' => 55,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
              'line' => 56,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets the messages produced by the domain layer.
     *
     * @param mixed $messages The messages produced by the domain layer.
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
                  'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                  'line' => 56,
                  'char' => 68,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                'line' => 56,
                'char' => 68,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
            'line' => 56,
            'char' => 68,
          ),
          'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
          'line' => 56,
          'last-line' => 62,
          'char' => 19,
        ),
        4 => 
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
              'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
              'line' => 63,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets arbitrary extra values produced by the domain layer.
     *
     * @param mixed $extras Arbitrary extra values produced by the domain layer.
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
                  'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                  'line' => 63,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
                'line' => 63,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
            'line' => 63,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
          'line' => 63,
          'last-line' => 64,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
      'line' => 64,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Domain/Payload/WriteableInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);