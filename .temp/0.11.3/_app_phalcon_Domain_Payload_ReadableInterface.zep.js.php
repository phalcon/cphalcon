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
    'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Domain\\Payload',
    'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
    'line' => 23,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This interface is used for consumers (read only)
 *',
    'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
    'line' => 24,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'ReadableInterface',
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
          'name' => 'getStatus',
          'docblock' => '**
     * Gets the status of this payload.
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
                'line' => 31,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
            'line' => 31,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
          'line' => 31,
          'last-line' => 37,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getInput',
          'docblock' => '**
     * Gets the input received by the domain layer.
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
                'line' => 38,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
            'line' => 38,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
          'line' => 38,
          'last-line' => 44,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOutput',
          'docblock' => '**
     * Gets the output produced from the domain layer.
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
                'line' => 45,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
            'line' => 45,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
          'line' => 45,
          'last-line' => 51,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'docblock' => '**
     * Gets the messages produced by the domain layer.
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
                'line' => 52,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
            'line' => 52,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
          'line' => 52,
          'last-line' => 58,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getExtras',
          'docblock' => '**
     * Gets arbitrary extra values produced by the domain layer.
     *
     * @param mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
                'line' => 59,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
            'line' => 59,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
          'line' => 59,
          'last-line' => 60,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
      'line' => 60,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Domain/Payload/ReadableInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);