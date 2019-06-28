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
    'file' => '/app/phalcon/Forms/Element/Text.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Forms\\Element',
    'file' => '/app/phalcon/Forms/Element/Text.zep',
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
        'name' => 'Phalcon\\Tag',
        'file' => '/app/phalcon/Forms/Element/Text.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Forms/Element/Text.zep',
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
        'name' => 'Phalcon\\Forms\\Element',
        'file' => '/app/phalcon/Forms/Element/Text.zep',
        'line' => 14,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Forms/Element/Text.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Forms\\Element\\Text
 *
 * Component INPUT[type=text] for forms
 *',
    'file' => '/app/phalcon/Forms/Element/Text.zep',
    'line' => 21,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Text',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Element',
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
          'name' => 'render',
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
                'file' => '/app/phalcon/Forms/Element/Text.zep',
                'line' => 26,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Element/Text.zep',
              'line' => 26,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Tag',
                'dynamic' => 0,
                'name' => 'textField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Forms/Element/Text.zep',
                        'line' => 29,
                        'char' => 18,
                      ),
                      'name' => 'prepareAttributes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attributes',
                            'file' => '/app/phalcon/Forms/Element/Text.zep',
                            'line' => 29,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Forms/Element/Text.zep',
                          'line' => 29,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Forms/Element/Text.zep',
                      'line' => 30,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Forms/Element/Text.zep',
                    'line' => 30,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Forms/Element/Text.zep',
                'line' => 30,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Forms/Element/Text.zep',
              'line' => 31,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders the element widget
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
                'file' => '/app/phalcon/Forms/Element/Text.zep',
                'line' => 27,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/Element/Text.zep',
            'line' => 27,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Element/Text.zep',
          'line' => 26,
          'last-line' => 32,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Forms/Element/Text.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Forms/Element/Text.zep',
    'line' => 21,
    'char' => 5,
  ),
);