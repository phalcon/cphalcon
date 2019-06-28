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
    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Translate\\Adapter',
    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
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
        'name' => 'ArrayAccess',
        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
    'line' => 14,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Translate\\Exception',
        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Translate\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
        'line' => 15,
        'char' => 46,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Translate\\InterpolatorFactory',
        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
        'line' => 16,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
    'line' => 22,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Translate\\Adapter\\Csv
 *
 * Allows to define translation lists using CSV file
 *',
    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
    'line' => 23,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Csv',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ArrayAccess',
        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
        'line' => 24,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'translate',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
            'line' => 28,
            'char' => 29,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
          'line' => 32,
          'char' => 6,
        ),
      ),
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
              'name' => 'interpolator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'InterpolatorFactory',
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 33,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 33,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 33,
              'char' => 83,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'delimiter',
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 35,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'enclosure',
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 35,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 37,
              'char' => 14,
            ),
            1 => 
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
                      'type' => 'variable',
                      'value' => 'interpolator',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 37,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 37,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 37,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 37,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 37,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 39,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 39,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'content',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 39,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 39,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 39,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 39,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 39,
                'char' => 45,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Parameter \'content\' is required',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 40,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 40,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 40,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 41,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 43,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 43,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'delimiter',
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 43,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 43,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 43,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'delimiter',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 44,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'delimiter',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 44,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 44,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 44,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 45,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'delimiter',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => ';',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 46,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 46,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 47,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 49,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 49,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'enclosure',
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 49,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 49,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 49,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'enclosure',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 50,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'enclosure',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 50,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 50,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 50,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 51,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'enclosure',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '\\"',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 52,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 52,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 53,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 55,
              'char' => 12,
            ),
            5 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 55,
                  'char' => 14,
                ),
                'name' => 'load',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 55,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'content',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 55,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 55,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 55,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 55,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 55,
                    'char' => 39,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'delimiter',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 55,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 55,
                    'char' => 50,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'enclosure',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 55,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 55,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 55,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 56,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Translate\\Adapter\\Csv constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
            'line' => 34,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
          'line' => 33,
          'last-line' => 60,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 61,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 63,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translate',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 63,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 63,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 63,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 63,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 63,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 64,
              'char' => 5,
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
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 62,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
            'line' => 62,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
          'line' => 61,
          'last-line' => 68,
          'char' => 19,
        ),
        2 => 
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
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 69,
              'char' => 40,
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
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 69,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 69,
              'char' => 61,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'translation',
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 71,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 73,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'translation',
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 73,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 73,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'translate',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 73,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 73,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 73,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 73,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 73,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 73,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'translation',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'index',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 74,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 74,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 75,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 77,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 77,
                  'char' => 21,
                ),
                'name' => 'replacePlaceholders',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translation',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 77,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 77,
                    'char' => 53,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeholders',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 77,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 77,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 77,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 78,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the translation related to the given key
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
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 70,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
            'line' => 70,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
          'line' => 69,
          'last-line' => 82,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'load',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 83,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'length',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 83,
              'char' => 50,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'delimiter',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 83,
              'char' => 68,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'enclosure',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 83,
              'char' => 86,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 85,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'fileHandler',
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 85,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 87,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'fileHandler',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'fopen',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'file',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 87,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 87,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'rb',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 87,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 87,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 87,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 87,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 89,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fileHandler',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 89,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 89,
                    'char' => 42,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'resource',
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 89,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 89,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 89,
                'char' => 53,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Error opening translation file \'',
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 91,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 91,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 91,
                            'char' => 57,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\'',
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 92,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 92,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 92,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 92,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 95,
              'char' => 12,
            ),
            3 => 
            array (
              'type' => 'loop',
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'fgetcsv',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'fileHandler',
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 96,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 96,
                            'char' => 43,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'length',
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 96,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 96,
                            'char' => 51,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'delimiter',
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 96,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 96,
                            'char' => 62,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'enclosure',
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 96,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 96,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 96,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 96,
                      'char' => 74,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 98,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 98,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 98,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 98,
                    'char' => 31,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 100,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 102,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'substr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'data',
                                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                                'line' => 102,
                                'char' => 27,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                                'line' => 102,
                                'char' => 29,
                              ),
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 102,
                              'char' => 30,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 102,
                            'char' => 30,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 102,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 102,
                            'char' => 33,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                              'line' => 102,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 102,
                            'char' => 36,
                          ),
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 102,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '#',
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 102,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 102,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 102,
                            'char' => 58,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 102,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 102,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 102,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 102,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 102,
                    'char' => 62,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 104,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 106,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'translate',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 106,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                            'line' => 106,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 106,
                          'char' => 40,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 106,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                          'line' => 106,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                        'line' => 106,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 106,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                  'line' => 107,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 109,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'fclose',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fileHandler',
                      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                      'line' => 109,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                    'line' => 109,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
                'line' => 109,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
              'line' => 110,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Load translates from file
    *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
            'line' => 84,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
          'line' => 83,
          'last-line' => 111,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
      'line' => 23,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Translate/Adapter/Csv.zep',
    'line' => 23,
    'char' => 5,
  ),
);