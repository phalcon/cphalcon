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
    'file' => '/app/phalcon/Flash/FlashInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Flash',
    'file' => '/app/phalcon/Flash/FlashInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\FlashInterface
 *
 * Interface for Phalcon\\Flash
 *',
    'file' => '/app/phalcon/Flash/FlashInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'FlashInterface',
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
          'name' => 'error',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/FlashInterface.zep',
              'line' => 23,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Shows a HTML error message
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
                'file' => '/app/phalcon/Flash/FlashInterface.zep',
                'line' => 23,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/FlashInterface.zep',
            'line' => 23,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Flash/FlashInterface.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'message',
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
              'file' => '/app/phalcon/Flash/FlashInterface.zep',
              'line' => 28,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/FlashInterface.zep',
              'line' => 28,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Outputs a message
     *',
          'file' => '/app/phalcon/Flash/FlashInterface.zep',
          'line' => 28,
          'last-line' => 32,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notice',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/FlashInterface.zep',
              'line' => 33,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Shows a HTML notice/information message
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
                'file' => '/app/phalcon/Flash/FlashInterface.zep',
                'line' => 33,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/FlashInterface.zep',
            'line' => 33,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Flash/FlashInterface.zep',
          'line' => 33,
          'last-line' => 37,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'success',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/FlashInterface.zep',
              'line' => 38,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Shows a HTML success message
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
                'file' => '/app/phalcon/Flash/FlashInterface.zep',
                'line' => 38,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/FlashInterface.zep',
            'line' => 38,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Flash/FlashInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'warning',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/FlashInterface.zep',
              'line' => 43,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Shows a HTML warning message
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
                'file' => '/app/phalcon/Flash/FlashInterface.zep',
                'line' => 43,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/FlashInterface.zep',
            'line' => 43,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Flash/FlashInterface.zep',
          'line' => 43,
          'last-line' => 44,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Flash/FlashInterface.zep',
      'line' => 44,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Flash/FlashInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);