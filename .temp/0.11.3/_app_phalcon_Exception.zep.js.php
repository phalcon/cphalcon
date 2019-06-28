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
    'file' => '/app/phalcon/Exception.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Exception.zep',
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
        'name' => 'Throwable',
        'file' => '/app/phalcon/Exception.zep',
        'line' => 13,
        'char' => 14,
      ),
    ),
    'file' => '/app/phalcon/Exception.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Exception
 *
 * All framework exceptions should use or extend this exception
 *',
    'file' => '/app/phalcon/Exception.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Exception',
    'abstract' => 0,
    'final' => 0,
    'extends' => '\\Exception',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'Throwable',
        'file' => '/app/phalcon/Exception.zep',
        'line' => 21,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'containerServiceNotFound',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'service',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Exception.zep',
              'line' => 22,
              'char' => 68,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => 'A dependency injection container is required to access ',
                  'file' => '/app/phalcon/Exception.zep',
                  'line' => 24,
                  'char' => 72,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'service',
                  'file' => '/app/phalcon/Exception.zep',
                  'line' => 24,
                  'char' => 81,
                ),
                'file' => '/app/phalcon/Exception.zep',
                'line' => 24,
                'char' => 81,
              ),
              'file' => '/app/phalcon/Exception.zep',
              'line' => 25,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Exception.zep',
                'line' => 23,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Exception.zep',
            'line' => 23,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Exception.zep',
          'line' => 22,
          'last-line' => 26,
          'char' => 26,
        ),
      ),
      'file' => '/app/phalcon/Exception.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Exception.zep',
    'line' => 20,
    'char' => 5,
  ),
);