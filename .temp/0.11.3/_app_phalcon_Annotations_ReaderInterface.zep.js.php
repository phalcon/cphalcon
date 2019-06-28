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
    'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations',
    'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Parses docblocks returning an array with the found annotations
 *',
    'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'ReaderInterface',
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
          'name' => 'parse',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
              'line' => 21,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Reads annotations from the class docblocks, its methods and/or properties
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
                'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
                'line' => 21,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
            'line' => 21,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
          'line' => 21,
          'last-line' => 25,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'parseDocBlock',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'docBlock',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
              'line' => 26,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
                'line' => 26,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
              'line' => 26,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'line',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
                'line' => 26,
                'char' => 83,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
              'line' => 26,
              'char' => 83,
            ),
          ),
          'docblock' => '**
     * Parses a raw docblock returning the annotations found
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
                'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
                'line' => 26,
                'char' => 93,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
            'line' => 26,
            'char' => 93,
          ),
          'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
          'line' => 26,
          'last-line' => 27,
          'char' => 26,
        ),
      ),
      'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
      'line' => 27,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Annotations/ReaderInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);