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
    'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter\\Sanitize',
    'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Filter\\Sanitize\\Remove
 *
 * Sanitizes a value removing parts of a string
 *',
    'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Remove',
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
              'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
              'line' => 23,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'replace',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
              'line' => 23,
              'char' => 52,
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
                'name' => 'str_replace',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'replace',
                      'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
                      'line' => 25,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
                    'line' => 25,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '',
                      'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
                      'line' => 25,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
                    'line' => 25,
                    'char' => 37,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'input',
                      'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
                      'line' => 25,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
                    'line' => 25,
                    'char' => 44,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
                'line' => 25,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
              'line' => 26,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var mixed input The text to sanitize
     *',
          'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Sanitize/Remove.zep',
    'line' => 18,
    'char' => 5,
  ),
);