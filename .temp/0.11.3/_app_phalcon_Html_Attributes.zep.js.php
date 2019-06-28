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
    'file' => '/app/phalcon/Html/Attributes.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html',
    'file' => '/app/phalcon/Html/Attributes.zep',
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
        'name' => 'Phalcon\\Collection\\Collection',
        'file' => '/app/phalcon/Html/Attributes.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Html/Attributes.zep',
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
        'name' => 'Phalcon\\Html\\Attributes\\RenderInterface',
        'file' => '/app/phalcon/Html/Attributes.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Html/Attributes.zep',
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
        'name' => 'Phalcon\\Tag',
        'file' => '/app/phalcon/Html/Attributes.zep',
        'line' => 15,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Html/Attributes.zep',
    'line' => 19,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class helps to work with HTML Attributes
 *',
    'file' => '/app/phalcon/Html/Attributes.zep',
    'line' => 20,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Attributes',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Collection',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RenderInterface',
        'file' => '/app/phalcon/Html/Attributes.zep',
        'line' => 21,
        'char' => 1,
      ),
    ),
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
                'name' => 'renderAttributes',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '',
                      'file' => '/app/phalcon/Html/Attributes.zep',
                      'line' => 27,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Attributes.zep',
                    'line' => 27,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Attributes.zep',
                        'line' => 27,
                        'char' => 45,
                      ),
                      'name' => 'toArray',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Html/Attributes.zep',
                      'line' => 27,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Html/Attributes.zep',
                    'line' => 27,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Html/Attributes.zep',
                'line' => 27,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Html/Attributes.zep',
              'line' => 28,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Render attributes as HTML attributes
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
                'file' => '/app/phalcon/Html/Attributes.zep',
                'line' => 26,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Attributes.zep',
            'line' => 26,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Attributes.zep',
          'line' => 25,
          'last-line' => 32,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__toString',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Attributes.zep',
                  'line' => 35,
                  'char' => 21,
                ),
                'name' => 'render',
                'call-type' => 1,
                'file' => '/app/phalcon/Html/Attributes.zep',
                'line' => 35,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Html/Attributes.zep',
              'line' => 36,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Alias of the render method
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
                'file' => '/app/phalcon/Html/Attributes.zep',
                'line' => 34,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Attributes.zep',
            'line' => 34,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Attributes.zep',
          'line' => 33,
          'last-line' => 37,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Attributes.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Attributes.zep',
    'line' => 20,
    'char' => 5,
  ),
);