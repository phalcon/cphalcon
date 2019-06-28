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
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 *',
    'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message\\Stream',
    'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
    'line' => 17,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Message\\Stream',
        'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
    'line' => 25,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Describes a data stream from "php://temp"
 *
 * Typically, an instance will wrap a PHP stream; this interface provides
 * a wrapper around the most common operations, including serialization of
 * the entire stream to a string.
 *',
    'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
    'line' => 26,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Temp',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Stream',
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
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'mode',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'rb',
                'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
                'line' => 31,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
              'line' => 31,
              'char' => 46,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'php://temp',
                      'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
                      'line' => 33,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
                    'line' => 33,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mode',
                      'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
                      'line' => 33,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
                    'line' => 33,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
                'line' => 33,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
              'line' => 34,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
            'line' => 32,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
      'line' => 26,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Message/Stream/Temp.zep',
    'line' => 26,
    'char' => 5,
  ),
);