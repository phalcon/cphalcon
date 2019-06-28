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
    'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Translate\\Adapter',
    'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Translate\\AdapterInterface
 *
 * Interface for Phalcon\\Translate adapters
 *',
    'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'AdapterInterface',
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
          'name' => 'exists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
              'line' => 23,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Check whether is defined a translation key in the internal array
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
                'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
                'line' => 23,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
            'line' => 23,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
          'line' => 23,
          'last-line' => 29,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'query',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'translateKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
              'line' => 30,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
                'line' => 30,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
              'line' => 30,
              'char' => 68,
            ),
          ),
          'docblock' => '**
     * Returns the translation related to the given key
     *
     * @param array placeholders
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
                'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
                'line' => 30,
                'char' => 79,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
            'line' => 30,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
          'line' => 30,
          'last-line' => 36,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 't',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'translateKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
              'line' => 37,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
                'line' => 37,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
              'line' => 37,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Returns the translation string of the given key
     *
     * @param array placeholders
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
                'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
                'line' => 37,
                'char' => 75,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
            'line' => 37,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
          'line' => 37,
          'last-line' => 38,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
      'line' => 38,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Translate/Adapter/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);