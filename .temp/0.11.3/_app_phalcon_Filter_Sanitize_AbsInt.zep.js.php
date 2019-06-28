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
    'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter\\Sanitize',
    'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Filter\\Sanitize\\AbsInt
 *
 * Sanitizes a value to absolute integer
 *',
    'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'AbsInt',
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
              'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
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
                'name' => 'abs',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'intval',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
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
                                  'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                                  'line' => 27,
                                  'char' => 33,
                                ),
                                'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                                'line' => 27,
                                'char' => 33,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'constant',
                                  'value' => 'FILTER_SANITIZE_NUMBER_INT',
                                  'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                                  'line' => 27,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                                'line' => 27,
                                'char' => 61,
                              ),
                            ),
                            'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                            'line' => 28,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                          'line' => 28,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                      'line' => 29,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                    'line' => 29,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
                'line' => 29,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
              'line' => 30,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var mixed input The text to sanitize
     *',
          'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
          'line' => 23,
          'last-line' => 31,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Sanitize/AbsInt.zep',
    'line' => 18,
    'char' => 5,
  ),
);