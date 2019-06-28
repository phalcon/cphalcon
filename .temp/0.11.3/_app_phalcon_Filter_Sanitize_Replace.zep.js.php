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
    'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter\\Sanitize',
    'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Filter\\Sanitize\\Replace
 *
 * Sanitizes a value replacing parts of a string
 *',
    'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Replace',
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
              'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
              'line' => 23,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'from',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
              'line' => 23,
              'char' => 49,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'to',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
              'line' => 23,
              'char' => 57,
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
                      'value' => 'from',
                      'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
                      'line' => 25,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
                    'line' => 25,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'to',
                      'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
                      'line' => 25,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
                    'line' => 25,
                    'char' => 36,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'input',
                      'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
                      'line' => 25,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
                    'line' => 25,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
                'line' => 25,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
              'line' => 26,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var mixed input The text to sanitize
     *',
          'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Sanitize/Replace.zep',
    'line' => 18,
    'char' => 5,
  ),
);