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
    'file' => '/app/phalcon/Html/Helper/Form.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html\\Helper',
    'file' => '/app/phalcon/Html/Helper/Form.zep',
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
        'name' => 'Phalcon\\Html\\Helper\\AbstractHelper',
        'file' => '/app/phalcon/Html/Helper/Form.zep',
        'line' => 13,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Html/Helper/Form.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Helper\\Form
 *
 * Creates a form opening tag
 *',
    'file' => '/app/phalcon/Html/Helper/Form.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Form',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractHelper',
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
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/Form.zep',
                'line' => 25,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/Form.zep',
              'line' => 25,
              'char' => 51,
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
                  'variable' => 'overrides',
                  'file' => '/app/phalcon/Html/Helper/Form.zep',
                  'line' => 27,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/Form.zep',
              'line' => 29,
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
                  'variable' => 'overrides',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'method',
                          'file' => '/app/phalcon/Html/Helper/Form.zep',
                          'line' => 30,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'post',
                          'file' => '/app/phalcon/Html/Helper/Form.zep',
                          'line' => 30,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Html/Helper/Form.zep',
                        'line' => 30,
                        'char' => 27,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'enctype',
                          'file' => '/app/phalcon/Html/Helper/Form.zep',
                          'line' => 31,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'multipart/form-data',
                          'file' => '/app/phalcon/Html/Helper/Form.zep',
                          'line' => 32,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Html/Helper/Form.zep',
                        'line' => 32,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Helper/Form.zep',
                    'line' => 32,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Html/Helper/Form.zep',
                  'line' => 32,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/Form.zep',
              'line' => 34,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'overrides',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Helper/Form.zep',
                      'line' => 34,
                      'char' => 30,
                    ),
                    'name' => 'orderAttributes',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'overrides',
                          'file' => '/app/phalcon/Html/Helper/Form.zep',
                          'line' => 34,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Html/Helper/Form.zep',
                        'line' => 34,
                        'char' => 56,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Html/Helper/Form.zep',
                          'line' => 34,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Html/Helper/Form.zep',
                        'line' => 34,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Helper/Form.zep',
                    'line' => 34,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Html/Helper/Form.zep',
                  'line' => 34,
                  'char' => 69,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/Form.zep',
              'line' => 36,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Helper/Form.zep',
                  'line' => 36,
                  'char' => 21,
                ),
                'name' => 'renderElement',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'form',
                      'file' => '/app/phalcon/Html/Helper/Form.zep',
                      'line' => 36,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Form.zep',
                    'line' => 36,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'overrides',
                      'file' => '/app/phalcon/Html/Helper/Form.zep',
                      'line' => 36,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Form.zep',
                    'line' => 36,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Html/Helper/Form.zep',
                'line' => 36,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Html/Helper/Form.zep',
              'line' => 37,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var array  attributes Any additional attributes
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
                'file' => '/app/phalcon/Html/Helper/Form.zep',
                'line' => 26,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/Form.zep',
            'line' => 26,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/Form.zep',
          'line' => 25,
          'last-line' => 38,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Helper/Form.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Helper/Form.zep',
    'line' => 20,
    'char' => 5,
  ),
);