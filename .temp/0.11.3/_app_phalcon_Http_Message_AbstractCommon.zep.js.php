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
    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Exception\\InvalidArgumentException',
        'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
        'line' => 17,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
    'line' => 21,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Common methods
 *',
    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
    'line' => 22,
    'char' => 8,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'AbstractCommon',
    'abstract' => 1,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'cloneInstance',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 32,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'property',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 32,
              'char' => 72,
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
                  'variable' => 'newInstance',
                  'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                  'line' => 34,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 36,
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
                  'variable' => 'newInstance',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                      'line' => 36,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                    'line' => 36,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                  'line' => 36,
                  'char' => 49,
                ),
                1 => 
                array (
                  'assign-type' => 'variable-dynamic-object-property',
                  'operator' => 'assign',
                  'variable' => 'newInstance',
                  'property' => 'property',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'element',
                    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                    'line' => 37,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                  'line' => 37,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 39,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'newInstance',
                'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                'line' => 39,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 40,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a new instance having set the parameter
     *
     * @param mixed  $element
     * @param string $property
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                'line' => 33,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
          'line' => 32,
          'last-line' => 46,
          'char' => 28,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkStringParameter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 47,
              'char' => 58,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'element',
                    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                    'line' => 49,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                  'line' => 49,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                  'line' => 49,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                'line' => 49,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Method requires a string argument',
                          'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                          'line' => 52,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                        'line' => 52,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                    'line' => 52,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                  'line' => 53,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 54,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the element passed if it is a string
     *
     * @param mixed $element
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
            'line' => 48,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
          'line' => 47,
          'last-line' => 64,
          'char' => 28,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'processWith',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 65,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'property',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 65,
              'char' => 70,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                  'line' => 67,
                  'char' => 14,
                ),
                'name' => 'checkStringParameter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                      'line' => 67,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                    'line' => 67,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                'line' => 67,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 69,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                  'line' => 69,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                      'line' => 69,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                    'line' => 69,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'property',
                      'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                      'line' => 69,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                    'line' => 69,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                'line' => 69,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
              'line' => 70,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the element passed; assigns it to the property and returns a
     * clone of the object back
     *
     * @param mixed  $element
     * @param string $property
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
                'line' => 66,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
            'line' => 66,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
          'line' => 65,
          'last-line' => 71,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
      'line' => 22,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Http/Message/AbstractCommon.zep',
    'line' => 22,
    'char' => 14,
  ),
);