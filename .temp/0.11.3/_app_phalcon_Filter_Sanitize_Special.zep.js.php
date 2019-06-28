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
    'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter\\Sanitize',
    'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Filter\\Sanitize\\Special
 *
 * Sanitizes a value special characters
 *',
    'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Special',
    'abstract' => 0,
    'final' => 0,
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
          'name' => '__invoke',
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
              'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
              'line' => 23,
              'char' => 39,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'filter_var',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'input',
                      'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
                      'line' => 25,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
                    'line' => 25,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'constant',
                      'value' => 'FILTER_SANITIZE_SPECIAL_CHARS',
                      'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
                      'line' => 25,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
                    'line' => 25,
                    'char' => 63,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
                'line' => 25,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
              'line' => 26,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var mixed input The text to sanitize
     *',
          'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Sanitize/Special.zep',
    'line' => 18,
    'char' => 5,
  ),
);