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
    'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter\\Sanitize',
    'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Filter\\Sanitize\\Regex
 *
 * Sanitizes a value performing preg_replace
 *',
    'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Regex',
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
              'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
              'line' => 23,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'pattern',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
              'line' => 23,
              'char' => 52,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'replace',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
              'line' => 23,
              'char' => 65,
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
                'name' => 'preg_replace',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
                      'line' => 25,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
                    'line' => 25,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'replace',
                      'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
                      'line' => 25,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
                    'line' => 25,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'input',
                      'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
                      'line' => 25,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
                    'line' => 25,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
                'line' => 25,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
              'line' => 26,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var mixed input The text to sanitize
     *',
          'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Sanitize/Regex.zep',
    'line' => 18,
    'char' => 5,
  ),
);