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
    'file' => '/app/phalcon/DispatcherInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/DispatcherInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Dispatcher
 *',
    'file' => '/app/phalcon/DispatcherInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'DispatcherInterface',
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
          'name' => 'dispatch',
          'docblock' => '**
     * Dispatches a handle action taking into account the routing parameters
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 21,
                'char' => 43,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 21,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 21,
            'char' => 49,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 21,
          'last-line' => 25,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'forward',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'forward',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 26,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Forwards the execution flow to another controller/action
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 26,
            'char' => 51,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActionName',
          'docblock' => '**
     * Gets last dispatched action name
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 31,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 31,
            'char' => 46,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActionSuffix',
          'docblock' => '**
     * Gets the default action suffix
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 36,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 36,
            'char' => 48,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 36,
          'last-line' => 40,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHandlerSuffix',
          'docblock' => '**
     * Gets the default handler suffix
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 41,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 41,
            'char' => 49,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 41,
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
          'name' => 'getParam',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'param',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 48,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 48,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 48,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Gets a param by its name or numeric index
     *
     * @param  string|array filters
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 48,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 48,
            'char' => 63,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
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
          'name' => 'getParams',
          'docblock' => '**
     * Gets action params
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 53,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 53,
            'char' => 41,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
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
          'name' => 'getReturnedValue',
          'docblock' => '**
     * Returns value returned by the latest dispatched action
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 58,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 58,
            'char' => 46,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
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
          'name' => 'hasParam',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'param',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 63,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Check if a param exists
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 63,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 63,
            'char' => 48,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 63,
          'last-line' => 68,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isFinished',
          'docblock' => '**
     * Checks if the dispatch loop is finished or has more pendent
     * controllers/tasks to dispatch
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
                'file' => '/app/phalcon/DispatcherInterface.zep',
                'line' => 69,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 69,
            'char' => 41,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 69,
          'last-line' => 73,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setActionName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'actionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 74,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Sets the action name to be dispatched
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 74,
            'char' => 61,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 74,
          'last-line' => 78,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setActionSuffix',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'actionSuffix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 79,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Sets the default action suffix
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 79,
            'char' => 65,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 79,
          'last-line' => 83,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultAction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'actionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 84,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Sets the default action name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 84,
            'char' => 64,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 84,
          'last-line' => 88,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultNamespace',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultNamespace',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 89,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Sets the default namespace
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 89,
            'char' => 73,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 89,
          'last-line' => 93,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHandlerSuffix',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handlerSuffix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 94,
              'char' => 58,
            ),
          ),
          'docblock' => '**
     * Sets the default suffix for the handler
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 94,
            'char' => 67,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 94,
          'last-line' => 98,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setModuleName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'moduleName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 99,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Sets the module name which the application belongs to
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 99,
            'char' => 61,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 99,
          'last-line' => 103,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setNamespaceName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'namespaceName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 104,
              'char' => 58,
            ),
          ),
          'docblock' => '**
     * Sets the namespace which the controller belongs to
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 104,
            'char' => 67,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 104,
          'last-line' => 110,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setParam',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'param',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 111,
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
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 111,
              'char' => 46,
            ),
          ),
          'docblock' => '**
     * Set a param by its name or numeric index
     *
     * @param  mixed value
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 111,
            'char' => 55,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 111,
          'last-line' => 115,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setParams',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/DispatcherInterface.zep',
              'line' => 116,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Sets action params to be dispatched
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/DispatcherInterface.zep',
            'line' => 116,
            'char' => 52,
          ),
          'file' => '/app/phalcon/DispatcherInterface.zep',
          'line' => 116,
          'last-line' => 117,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/DispatcherInterface.zep',
      'line' => 117,
      'char' => 1,
    ),
    'file' => '/app/phalcon/DispatcherInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);