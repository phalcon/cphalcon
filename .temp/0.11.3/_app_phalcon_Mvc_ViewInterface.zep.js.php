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
    'file' => '/app/phalcon/Mvc/ViewInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/ViewInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\ViewInterface
 *
 * Interface for Phalcon\\Mvc\\View
 *',
    'file' => '/app/phalcon/Mvc/ViewInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'ViewInterface',
    'extends' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ViewBaseInterface',
        'file' => '/app/phalcon/Mvc/ViewInterface.zep',
        'line' => 19,
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
          'name' => 'cleanTemplateAfter',
          'docblock' => '**
     * Resets any template before layouts
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'cleanTemplateBefore',
          'docblock' => '**
     * Resets any template before layouts
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 28,
          'last-line' => 32,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'disable',
          'docblock' => '**
     * Disables the auto-rendering process
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 33,
          'last-line' => 37,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'enable',
          'docblock' => '**
     * Enables the auto-rendering process
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'finish',
          'docblock' => '**
     * Finishes the render process by stopping the output buffering
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 43,
          'last-line' => 47,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActionName',
          'docblock' => '**
     * Gets the name of the action rendered
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 48,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 48,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActiveRenderPath',
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 53,
                'char' => 53,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 53,
                'char' => 60,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 53,
            'char' => 60,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 53,
          'last-line' => 57,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBasePath',
          'docblock' => '**
     * Gets base path
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 58,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 58,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 58,
          'last-line' => 62,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getControllerName',
          'docblock' => '**
     * Gets the name of the controller rendered
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 63,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 63,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 63,
          'last-line' => 67,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLayout',
          'docblock' => '**
     * Returns the name of the main view
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 68,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 68,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 68,
          'last-line' => 72,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLayoutsDir',
          'docblock' => '**
     * Gets the current layouts sub-directory
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 73,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 73,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 73,
          'last-line' => 77,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMainView',
          'docblock' => '**
     * Returns the name of the main view
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 78,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 78,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 78,
          'last-line' => 82,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPartialsDir',
          'docblock' => '**
     * Gets the current partials sub-directory
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 83,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 83,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 83,
          'last-line' => 87,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isDisabled',
          'docblock' => '**
     * Whether the automatic rendering is disabled
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
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 88,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 88,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 88,
          'last-line' => 92,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'pick',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'renderView',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 93,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Choose a view different to render than last-controller/last-action
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 93,
          'last-line' => 97,
          'char' => 19,
        ),
        15 => 
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
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 98,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Register templating engines
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 98,
          'last-line' => 102,
          'char' => 19,
        ),
        16 => 
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
              'name' => 'controllerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 103,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'actionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 103,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 103,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 103,
              'char' => 89,
            ),
          ),
          'docblock' => '**
     * Executes render process from dispatching data
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
                  'value' => 'ViewInterface',
                  'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                  'line' => 103,
                  'char' => 110,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 103,
                'char' => 110,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 103,
                'char' => 116,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 103,
            'char' => 116,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 103,
          'last-line' => 107,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
          'docblock' => '**
     * Resets the view component to its factory default values
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 108,
          'last-line' => 113,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBasePath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'basePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 114,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets base path. Depending of your platform, always add a trailing slash
     * or backslash
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 114,
          'last-line' => 119,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setLayout',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'layout',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 120,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Change the layout to be used instead of using the name of the latest
     * controller name
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 120,
          'last-line' => 126,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setLayoutsDir',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'layoutsDir',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 127,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Sets the layouts sub-directory. Must be a directory under the views
     * directory. Depending of your platform, always add a trailing slash or
     * backslash
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 127,
          'last-line' => 132,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setMainView',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewPath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 133,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets default view name. Must be a file without extension in the views
     * directory
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 133,
          'last-line' => 139,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPartialsDir',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'partialsDir',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 140,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Sets a partials sub-directory. Must be a directory under the views
     * directory. Depending of your platform, always add a trailing slash or
     * backslash
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 140,
          'last-line' => 144,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRenderLevel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'level',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 145,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets the render level for the view
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
                  'value' => 'ViewInterface',
                  'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                  'line' => 145,
                  'char' => 65,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ViewInterface.zep',
                'line' => 145,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewInterface.zep',
            'line' => 145,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 145,
          'last-line' => 151,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTemplateAfter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'templateAfter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 152,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Appends template after controller layout
     *
     * @param string|array templateAfter
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 152,
          'last-line' => 158,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTemplateBefore',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'templateBefore',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewInterface.zep',
              'line' => 159,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Appends template before controller layout
     *
     * @param string|array templateBefore
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 159,
          'last-line' => 163,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'start',
          'docblock' => '**
     * Starts rendering process enabling the output buffering
     *',
          'file' => '/app/phalcon/Mvc/ViewInterface.zep',
          'line' => 164,
          'last-line' => 165,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/ViewInterface.zep',
      'line' => 165,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/ViewInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);