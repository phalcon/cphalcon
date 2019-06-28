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
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\View',
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
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
        'name' => 'Closure',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
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
        'name' => 'Phalcon\\Di\\Injectable',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 15,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 16,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Helper\\Str',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 17,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\View\\Exception',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 18,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\ViewBaseInterface',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 19,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 20,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\View\\Engine\\EngineInterface',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 20,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 21,
    'char' => 3,
  ),
  10 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\View\\Engine\\Php',
        'alias' => 'PhpEngine',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 21,
        'char' => 45,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 49,
    'char' => 2,
  ),
  11 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\View\\Simple
 *
 * This component allows to render views without hierarchical levels
 *
 *```php
 * use Phalcon\\Mvc\\View\\Simple as View;
 *
 * $view = new View();
 *
 * // Render a view
 * echo $view->render(
 *     "templates/my-view",
 *     [
 *         "some" => $param,
 *     ]
 * );
 *
 * // Or with filename with extension
 * echo $view->render(
 *     "templates/my-view.volt",
 *     [
 *         "parameter" => $here,
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 50,
    'char' => 5,
  ),
  12 => 
  array (
    'type' => 'class',
    'name' => 'Simple',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Injectable',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ViewBaseInterface',
        'file' => '/app/phalcon/Mvc/View/Simple.zep',
        'line' => 51,
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
          'name' => 'activeRenderPath',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 53,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'content',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 57,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'engines',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 58,
            'char' => 30,
          ),
          'docblock' => '**
     * @var \\Phalcon\\Mvc\\View\\EngineInterface[]|false
     *',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 60,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'options',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 61,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'partialsDir',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 65,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'registeredEngines',
          'docblock' => '**
     * @var array|null
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 66,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 68,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'viewsDir',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 70,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'viewParams',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 70,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 74,
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
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 75,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 75,
              'char' => 51,
            ),
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 77,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 77,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 78,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\View\\Simple constructor
     *',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 75,
          'last-line' => 86,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 87,
              'char' => 38,
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 89,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 91,
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
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 91,
                    'char' => 48,
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
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 91,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'viewParams',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 91,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 91,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 91,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 91,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 91,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 91,
                'char' => 48,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 92,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 95,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 95,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 96,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic method to retrieve a variable passed to the view
     *
     *```php
     * echo $this->view->products;
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 87,
                'char' => 47,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 88,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 88,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 87,
          'last-line' => 104,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 105,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 105,
              'char' => 49,
            ),
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'viewParams',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 107,
                      'char' => 33,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 107,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 107,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 108,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic method to pass variables to the views
     *
     *```php
     * $this->view->products = $products;
     *```
     *',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 105,
          'last-line' => 112,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActiveRenderPath',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 115,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'activeRenderPath',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 115,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 115,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 116,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the path of the view that is currently rendered
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
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 113,
          'last-line' => 120,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getContent',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 123,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'content',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 123,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 123,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 124,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns output from another view stage
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
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 121,
          'last-line' => 128,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParamsToView',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 131,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'viewParams',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 131,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 131,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 132,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns parameters to views
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 130,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 130,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 129,
          'last-line' => 136,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getVar',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 137,
              'char' => 39,
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 139,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 141,
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
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 141,
                    'char' => 48,
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
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 141,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'viewParams',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 141,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 141,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 141,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 141,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 141,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 141,
                'char' => 48,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 142,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 143,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 145,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 145,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 146,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a parameter previously set in the view
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 137,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 138,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 138,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 137,
          'last-line' => 150,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getViewsDir',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 153,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'viewsDir',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 153,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 153,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 154,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets views directory
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
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 152,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 152,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 151,
          'last-line' => 173,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'partial',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'partialPath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 174,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 174,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 174,
              'char' => 67,
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
                  'variable' => 'viewParams',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 176,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'mergedParams',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 176,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 181,
              'char' => 16,
            ),
            1 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'ob_start',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 181,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 187,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 187,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 187,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 187,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 187,
                'char' => 35,
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
                      'variable' => 'viewParams',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 188,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'viewParams',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 188,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 188,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 188,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 193,
                  'char' => 15,
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
                      'variable' => 'mergedParams',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'array_merge',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'viewParams',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 193,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 193,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 193,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 193,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 193,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 193,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 198,
                  'char' => 31,
                ),
                2 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'create_symbol_table',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 198,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 199,
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
                      'variable' => 'mergedParams',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 200,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 200,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 201,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 206,
              'char' => 12,
            ),
            3 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 206,
                  'char' => 14,
                ),
                'name' => 'internalRender',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'partialPath',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 206,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 206,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mergedParams',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 206,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 206,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 206,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 211,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 211,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 211,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 211,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 211,
                'char' => 35,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'viewParams',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'viewParams',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 215,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 215,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 216,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 218,
              'char' => 20,
            ),
            5 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'ob_end_clean',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 218,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 223,
              'char' => 12,
            ),
            6 => 
            array (
              'type' => 'echo',
              'expressions' => 
              array (
                0 => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 223,
                    'char' => 19,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'content',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 223,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 223,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 224,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders a partial view
     *
     * ```php
     * // Show a partial inside another view
     * $this->partial("shared/footer");
     * ```
     *
     * ```php
     * // Show a partial inside another view with parameters
     * $this->partial(
     *     "shared/footer",
     *     [
     *         "content" => $html,
     *     ]
     * );
     * ```
     *',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 174,
          'last-line' => 238,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'registerEngines',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'engines',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 239,
              'char' => 51,
            ),
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'registeredEngines',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'engines',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 241,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 241,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 242,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Register templating engines
     *
     *```php
     * $this->view->registerEngines(
     *     [
     *         ".phtml" => \\Phalcon\\Mvc\\View\\Engine\\Php::class,
     *         ".volt"  => \\Phalcon\\Mvc\\View\\Engine\\Volt::class,
     *         ".mhtml" => \\MyCustomEngine::class,
     *     ]
     * );
     *```
     *',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 239,
          'last-line' => 246,
          'char' => 19,
        ),
        10 => 
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
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 247,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 247,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 247,
              'char' => 59,
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
                  'variable' => 'mergedParams',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 249,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'viewParams',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 249,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 254,
              'char' => 27,
            ),
            1 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'create_symbol_table',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 254,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 256,
              'char' => 16,
            ),
            2 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'ob_start',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 256,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 258,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'viewParams',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 258,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'viewParams',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 258,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 258,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 258,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 263,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'mergedParams',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_merge',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'viewParams',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 263,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 263,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 263,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 263,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 263,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 263,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 268,
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
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 268,
                  'char' => 14,
                ),
                'name' => 'internalRender',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 268,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 268,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mergedParams',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 268,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 268,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 268,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 270,
              'char' => 20,
            ),
            6 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'ob_end_clean',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 270,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 272,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 272,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'content',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 272,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 272,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 273,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders a view
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
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 248,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 248,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 247,
          'last-line' => 281,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setContent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 282,
              'char' => 47,
            ),
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'content',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'content',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 284,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 284,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 286,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 286,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 287,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Externally sets the view content
     *
     *```php
     * $this->view->setContent("<h1>hello</h1>");
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Simple',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 283,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 283,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 283,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 282,
          'last-line' => 295,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setParamToView',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 296,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 296,
              'char' => 58,
            ),
          ),
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
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 298,
                  'char' => 21,
                ),
                'name' => 'setVar',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 298,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 298,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 298,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 298,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 298,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 299,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds parameters to views (alias of setVar)
     *
     *```php
     * $this->view->setParamToView("products", $products);
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Simple',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 297,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 297,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 297,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 296,
          'last-line' => 307,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setVar',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 308,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 308,
              'char' => 50,
            ),
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'viewParams',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 310,
                      'char' => 33,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 310,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 310,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 312,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 312,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 313,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a single view parameter
     *
     *```php
     * $this->view->setVar("products", $products);
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Simple',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 309,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 309,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 309,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 308,
          'last-line' => 325,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setVars',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 326,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 326,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 326,
              'char' => 61,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'merge',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 328,
                'char' => 18,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'array_merge',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 329,
                                'char' => 43,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'viewParams',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 329,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 329,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 329,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 329,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 329,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 329,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 329,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 330,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 332,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'viewParams',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 332,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 332,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 334,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 334,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 335,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set all the render params
     *
     *```php
     * $this->view->setVars(
     *     [
     *         "products" => $products,
     *     ]
     * );
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Simple',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 327,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 327,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 327,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 326,
          'last-line' => 339,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setViewsDir',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewsDir',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 340,
              'char' => 49,
            ),
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'viewsDir',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Str',
                    'dynamic' => 0,
                    'name' => 'dirSeparator',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'viewsDir',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 342,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 342,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 342,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 342,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 343,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets views directory
     *',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 340,
          'last-line' => 348,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'loadTemplateEngines',
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
                  'variable' => 'engines',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 351,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'di',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 351,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'registeredEngines',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 351,
                  'char' => 43,
                ),
                3 => 
                array (
                  'variable' => 'extension',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 351,
                  'char' => 54,
                ),
                4 => 
                array (
                  'variable' => 'engineService',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 351,
                  'char' => 69,
                ),
                5 => 
                array (
                  'variable' => 'engineObject',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 352,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 357,
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
                  'variable' => 'engines',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 357,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'engines',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 357,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 357,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 357,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 359,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'engines',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 359,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 359,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 359,
                'char' => 30,
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
                      'variable' => 'di',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 360,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 360,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 360,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 360,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 362,
                  'char' => 15,
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
                      'variable' => 'engines',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 362,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 362,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 364,
                  'char' => 15,
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
                      'variable' => 'registeredEngines',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 364,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'registeredEngines',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 364,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 364,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 364,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 366,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'registeredEngines',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 366,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 366,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 366,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 366,
                    'char' => 50,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'engines',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => '.phtml',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 371,
                              'char' => 35,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'new',
                            'class' => 'PhpEngine',
                            'dynamic' => 0,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 371,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 371,
                                'char' => 57,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'di',
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 371,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 371,
                                'char' => 61,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 371,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 371,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 372,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'di',
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 373,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 373,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 373,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 373,
                        'char' => 40,
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
                                  'type' => 'scall',
                                  'dynamic-class' => 0,
                                  'class' => 'Exception',
                                  'dynamic' => 0,
                                  'name' => 'containerServiceNotFound',
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'the application services',
                                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                        'line' => 377,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                      'line' => 377,
                                      'char' => 25,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 378,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 378,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 378,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 379,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 381,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'registeredEngines',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 381,
                        'char' => 67,
                      ),
                      'key' => 'extension',
                      'value' => 'engineService',
                      'reverse' => 0,
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'engineService',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 382,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 382,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'object',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 382,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 382,
                            'char' => 55,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'instanceof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'engineService',
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 386,
                                  'char' => 51,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'Closure',
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 386,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 386,
                                'char' => 61,
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
                                      'variable' => 'engineService',
                                      'expr' => 
                                      array (
                                        'type' => 'scall',
                                        'dynamic-class' => 0,
                                        'class' => 'Closure',
                                        'dynamic' => 0,
                                        'name' => 'bind',
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'engineService',
                                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                              'line' => 387,
                                              'char' => 76,
                                            ),
                                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                            'line' => 387,
                                            'char' => 76,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'di',
                                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                              'line' => 387,
                                              'char' => 80,
                                            ),
                                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                            'line' => 387,
                                            'char' => 80,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                        'line' => 387,
                                        'char' => 81,
                                      ),
                                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                      'line' => 387,
                                      'char' => 81,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 389,
                                  'char' => 31,
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
                                      'variable' => 'engineObject',
                                      'expr' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'call_user_func',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'engineService',
                                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                              'line' => 389,
                                              'char' => 76,
                                            ),
                                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                            'line' => 389,
                                            'char' => 76,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'this',
                                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                              'line' => 389,
                                              'char' => 82,
                                            ),
                                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                            'line' => 389,
                                            'char' => 82,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                        'line' => 389,
                                        'char' => 83,
                                      ),
                                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                      'line' => 389,
                                      'char' => 83,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 390,
                                  'char' => 25,
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
                                      'variable' => 'engineObject',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'engineService',
                                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                        'line' => 391,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                      'line' => 391,
                                      'char' => 61,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 392,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 393,
                              'char' => 21,
                            ),
                          ),
                          'elseif_statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'equals',
                                'left' => 
                                array (
                                  'type' => 'typeof',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'engineService',
                                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                    'line' => 393,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 393,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'string',
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 393,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 393,
                                'char' => 61,
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
                                      'variable' => 'engineObject',
                                      'expr' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'di',
                                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                          'line' => 397,
                                          'char' => 47,
                                        ),
                                        'name' => 'getShared',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'engineService',
                                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                              'line' => 398,
                                              'char' => 42,
                                            ),
                                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                            'line' => 398,
                                            'char' => 42,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'array',
                                              'left' => 
                                              array (
                                                0 => 
                                                array (
                                                  'value' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'this',
                                                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                                    'line' => 401,
                                                    'char' => 29,
                                                  ),
                                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                                  'line' => 401,
                                                  'char' => 29,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                              'line' => 402,
                                              'char' => 25,
                                            ),
                                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                            'line' => 402,
                                            'char' => 25,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                        'line' => 402,
                                        'char' => 26,
                                      ),
                                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                      'line' => 402,
                                      'char' => 26,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 403,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 403,
                              'char' => 26,
                            ),
                          ),
                          'else_statements' => 
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
                                        'type' => 'string',
                                        'value' => 'Invalid template engine registration for extension: ',
                                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                        'line' => 405,
                                        'char' => 82,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'extension',
                                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                        'line' => 406,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                      'line' => 406,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                    'line' => 406,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 406,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 407,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 409,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'engines',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'extension',
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 409,
                                  'char' => 42,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'engineObject',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 409,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 409,
                              'char' => 58,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 410,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 411,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 413,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'engines',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'engines',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 413,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 413,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 414,
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
                      'variable' => 'engines',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 415,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'engines',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 415,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 415,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 415,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 416,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 418,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'engines',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 418,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 419,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Loads registered template engines, if none are registered it will use
     * Phalcon\\Mvc\\View\\Engine\\Php
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 350,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Simple.zep',
            'line' => 350,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 349,
          'last-line' => 425,
          'char' => 22,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'internalRender',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 426,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 426,
              'char' => 65,
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
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 428,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'engines',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 428,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'extension',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 428,
                  'char' => 46,
                ),
                3 => 
                array (
                  'variable' => 'engine',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 428,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 429,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'notExists',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 429,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'mustClean',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 429,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 430,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'viewEnginePath',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 430,
                  'char' => 30,
                ),
                1 => 
                array (
                  'variable' => 'viewsDirPath',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 430,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 432,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 432,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 432,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 432,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 432,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 434,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 434,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 434,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 434,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 434,
                'char' => 43,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'activeRenderPath',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'path',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 435,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 435,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 436,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 441,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 441,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 441,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 441,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 441,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 442,
                        'char' => 30,
                      ),
                      'name' => 'fire',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'view:beforeRender',
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 442,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 442,
                          'char' => 53,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 442,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 442,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 442,
                      'char' => 63,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 442,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 442,
                    'char' => 71,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 443,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 444,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 445,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 447,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'notExists',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 447,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 447,
                  'char' => 29,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'mustClean',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 448,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 448,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 450,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'viewsDirPath',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 450,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'viewsDir',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 450,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 450,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 450,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 450,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 450,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 455,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'engines',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 455,
                      'char' => 28,
                    ),
                    'name' => 'loadTemplateEngines',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 455,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 455,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 460,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'engines',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 460,
                'char' => 42,
              ),
              'key' => 'extension',
              'value' => 'engine',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'file_exists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'viewsDirPath',
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 461,
                            'char' => 41,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'extension',
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 461,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 461,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 461,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 461,
                    'char' => 54,
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
                          'variable' => 'viewEnginePath',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'viewsDirPath',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 462,
                              'char' => 51,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'extension',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 462,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 462,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 462,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 463,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'equals',
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
                                  'type' => 'variable',
                                  'value' => 'viewsDirPath',
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 463,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 463,
                                'char' => 41,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'minus',
                                  'left' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'strlen',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'extension',
                                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                          'line' => 463,
                                          'char' => 60,
                                        ),
                                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                        'line' => 463,
                                        'char' => 60,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                    'line' => 463,
                                    'char' => 61,
                                  ),
                                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                  'line' => 463,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 463,
                                'char' => 61,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 463,
                            'char' => 64,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'extension',
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 463,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 463,
                          'char' => 77,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'file_exists',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'viewsDirPath',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 463,
                                'char' => 103,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 463,
                              'char' => 103,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 463,
                          'char' => 105,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 463,
                        'char' => 105,
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
                              'variable' => 'viewEnginePath',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'viewsDirPath',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 468,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 468,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 469,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 469,
                      'char' => 18,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 471,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 476,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 476,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 476,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 476,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 476,
                    'char' => 47,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'eventsManager',
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 477,
                            'char' => 34,
                          ),
                          'name' => 'fire',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'view:beforeRenderView',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 477,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 477,
                              'char' => 61,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 477,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 477,
                              'char' => 67,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'viewEnginePath',
                                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                                'line' => 477,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 477,
                              'char' => 83,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 477,
                          'char' => 87,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 477,
                          'char' => 95,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 477,
                        'char' => 95,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 479,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 480,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 482,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'engine',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 482,
                      'char' => 20,
                    ),
                    'name' => 'render',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'viewEnginePath',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 482,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 482,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 482,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 482,
                        'char' => 50,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mustClean',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 482,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 482,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 482,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 484,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'notExists',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 484,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 484,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 489,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 489,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 489,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 489,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 489,
                    'char' => 47,
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
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 490,
                          'char' => 31,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'view:afterRenderView',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 490,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 490,
                            'char' => 57,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 490,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 490,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 490,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 491,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 493,
                  'char' => 17,
                ),
                5 => 
                array (
                  'type' => 'break',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 494,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 499,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'notExists',
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 499,
                'char' => 22,
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
                              'value' => 'View \'',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 501,
                              'char' => 24,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'viewsDirPath',
                              'file' => '/app/phalcon/Mvc/View/Simple.zep',
                              'line' => 501,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 501,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\' was not found in the views directory',
                            'file' => '/app/phalcon/Mvc/View/Simple.zep',
                            'line' => 502,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 502,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 502,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 502,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 503,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 508,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 508,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 508,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 508,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/View/Simple.zep',
                'line' => 508,
                'char' => 43,
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
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Mvc/View/Simple.zep',
                      'line' => 509,
                      'char' => 27,
                    ),
                    'name' => 'fire',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'view:afterRender',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 509,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 509,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/View/Simple.zep',
                          'line' => 509,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Simple.zep',
                        'line' => 509,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Simple.zep',
                    'line' => 509,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Simple.zep',
                  'line' => 510,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Simple.zep',
              'line' => 511,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Tries to render the view with every engine registered in the component
     *
     * @param array  params
     *',
          'file' => '/app/phalcon/Mvc/View/Simple.zep',
          'line' => 426,
          'last-line' => 512,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Mvc/View/Simple.zep',
      'line' => 50,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/View/Simple.zep',
    'line' => 50,
    'char' => 5,
  ),
);