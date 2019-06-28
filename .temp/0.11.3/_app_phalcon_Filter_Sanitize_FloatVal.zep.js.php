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
    'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter\\Sanitize',
    'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Filter\\Sanitize\\FloatVal
 *
 * Sanitizes a value to float
 *',
    'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'FloatVal',
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
              'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
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
                'type' => 'cast',
                'left' => 'double',
                'right' => 
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
                        'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                        'line' => 25,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                      'line' => 25,
                      'char' => 41,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'constant',
                        'value' => 'FILTER_SANITIZE_NUMBER_FLOAT',
                        'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                        'line' => 25,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                      'line' => 25,
                      'char' => 71,
                    ),
                    2 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'array',
                        'left' => 
                        array (
                          0 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'flags',
                              'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                              'line' => 25,
                              'char' => 79,
                            ),
                            'value' => 
                            array (
                              'type' => 'constant',
                              'value' => 'FILTER_FLAG_ALLOW_FRACTION',
                              'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                              'line' => 25,
                              'char' => 107,
                            ),
                            'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                            'line' => 25,
                            'char' => 107,
                          ),
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                        'line' => 25,
                        'char' => 108,
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                      'line' => 25,
                      'char' => 108,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                  'line' => 25,
                  'char' => 109,
                ),
                'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
                'line' => 25,
                'char' => 109,
              ),
              'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
              'line' => 26,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var mixed input The text to sanitize
     *',
          'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Sanitize/FloatVal.zep',
    'line' => 18,
    'char' => 5,
  ),
);