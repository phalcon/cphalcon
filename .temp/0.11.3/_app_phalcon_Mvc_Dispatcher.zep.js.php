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
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
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
        'name' => 'Phalcon\\Mvc\\DispatcherInterface',
        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
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
        'name' => 'Phalcon\\Mvc\\Dispatcher\\Exception',
        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
        'line' => 14,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
        'line' => 15,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
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
        'name' => 'Phalcon\\Http\\ResponseInterface',
        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
        'line' => 16,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
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
        'name' => 'Phalcon\\Mvc\\ControllerInterface',
        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
        'line' => 17,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
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
        'name' => 'Phalcon\\Dispatcher',
        'alias' => 'BaseDispatcher',
        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
        'line' => 18,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
    'line' => 39,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Dispatching is the process of taking the request object, extracting the
 * module name, controller name, action name, and optional parameters contained
 * in it, and then instantiating a controller and calling an action of that
 * controller.
 *
 *```php
 * $di = new \\Phalcon\\Di();
 *
 * $dispatcher = new \\Phalcon\\Mvc\\Dispatcher();
 *
 * $dispatcher->setDI($di);
 *
 * $dispatcher->setControllerName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $controller = $dispatcher->dispatch();
 *```
 *',
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
    'line' => 40,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Dispatcher',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'BaseDispatcher',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'DispatcherInterface',
        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
        'line' => 41,
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
          'name' => 'defaultAction',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'index',
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 42,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 44,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultHandler',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'index',
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 44,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 46,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'handlerSuffix',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Controller',
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 46,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 106,
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
          'name' => 'forward',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'forward',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 107,
              'char' => 40,
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 109,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 111,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 111,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 111,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 111,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 111,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 111,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 111,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 113,
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 113,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 113,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 113,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 113,
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
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 114,
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
                          'value' => 'dispatch:beforeForward',
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 114,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 114,
                        'char' => 55,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 114,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 114,
                        'char' => 61,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'forward',
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 114,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 114,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 114,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 115,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 117,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'forward',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'forward',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 117,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 117,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 117,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 118,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Forwards the execution flow to another controller/action.
     *
     * ```php
     * use Phalcon\\Events\\Event;
     * use Phalcon\\Mvc\\Dispatcher;
     * use App\\Backend\\Bootstrap as Backend;
     * use App\\Frontend\\Bootstrap as Frontend;
     *
     * // Registering modules
     * $modules = [
     *     "frontend" => [
     *         "className" => Frontend::class,
     *         "path"      => __DIR__ . "/app/Modules/Frontend/Bootstrap.php",
     *         "metadata"  => [
     *             "controllersNamespace" => "App\\Frontend\\Controllers",
     *         ],
     *     ],
     *     "backend" => [
     *         "className" => Backend::class,
     *         "path"      => __DIR__ . "/app/Modules/Backend/Bootstrap.php",
     *         "metadata"  => [
     *             "controllersNamespace" => "App\\Backend\\Controllers",
     *         ],
     *     ],
     * ];
     *
     * $application->registerModules($modules);
     *
     * // Setting beforeForward listener
     * $eventsManager  = $di->getShared("eventsManager");
     *
     * $eventsManager->attach(
     *     "dispatch:beforeForward",
     *     function(Event $event, Dispatcher $dispatcher, array $forward) use ($modules) {
     *         $metadata = $modules[$forward["module"]]["metadata"];
     *
     *         $dispatcher->setModuleName(
     *             $forward["module"]
     *         );
     *
     *         $dispatcher->setNamespaceName(
     *             $metadata["controllersNamespace"]
     *         );
     *     }
     * );
     *
     * // Forward
     * $this->dispatcher->forward(
     *     [
     *         "module"     => "backend",
     *         "controller" => "posts",
     *         "action"     => "index",
     *     ]
     * );
     * ```
     *
     * @param array forward
     *',
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 107,
          'last-line' => 122,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActiveController',
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 125,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'activeHandler',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 125,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 125,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 126,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the active controller in the dispatcher
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
                  'value' => 'ControllerInterface',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 124,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 124,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 124,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 123,
          'last-line' => 131,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getControllerClass',
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 134,
                  'char' => 21,
                ),
                'name' => 'getHandlerClass',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 134,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 135,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Possible controller class name that will be located to dispatch the
     * request
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
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 133,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 133,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 132,
          'last-line' => 139,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getControllerName',
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 142,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'handlerName',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 142,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 142,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets last dispatched controller name
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
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 141,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 141,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 140,
          'last-line' => 147,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLastController',
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 150,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'lastHandler',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 150,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 150,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 151,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the latest dispatched controller
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
                  'value' => 'ControllerInterface',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 149,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 149,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 149,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 148,
          'last-line' => 155,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPreviousActionName',
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 158,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'previousActionName',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 158,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 158,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 159,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets previous dispatched action name
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
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 157,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 157,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 156,
          'last-line' => 163,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPreviousControllerName',
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 166,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'previousHandlerName',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 166,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 166,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 167,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets previous dispatched controller name
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
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 165,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 165,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 164,
          'last-line' => 171,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPreviousNamespaceName',
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 174,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'previousNamespaceName',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 174,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 174,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets previous dispatched namespace name
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
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 173,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
            'line' => 173,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 172,
          'last-line' => 179,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setControllerName',
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
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 180,
              'char' => 61,
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
                  'property' => 'handlerName',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'controllerName',
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 182,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 182,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 183,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the controller name to be dispatched
     *',
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 180,
          'last-line' => 187,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setControllerSuffix',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'controllerSuffix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 188,
              'char' => 65,
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
                  'property' => 'handlerSuffix',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'controllerSuffix',
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 190,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 190,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 191,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default controller suffix
     *',
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 188,
          'last-line' => 195,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultController',
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
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 196,
              'char' => 64,
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
                  'property' => 'defaultHandler',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'controllerName',
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 198,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 198,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 199,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default controller name
     *',
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 196,
          'last-line' => 203,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'handleException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'exception',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => '\\Exception',
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 204,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 204,
              'char' => 62,
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
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 206,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 208,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 208,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 208,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 208,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 208,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 208,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 208,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 210,
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 210,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 210,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 210,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 210,
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
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 211,
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
                            'value' => 'dispatch:beforeException',
                            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                            'line' => 211,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 211,
                          'char' => 60,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                            'line' => 211,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 211,
                          'char' => 66,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'exception',
                            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                            'line' => 211,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 211,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 211,
                      'char' => 81,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 211,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 211,
                    'char' => 89,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 212,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 213,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 214,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 215,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Handles a user exception
     *',
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 204,
          'last-line' => 219,
          'char' => 22,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'throwDispatchException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 220,
              'char' => 62,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'exceptionCode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 220,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 220,
              'char' => 85,
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 222,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'response',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 222,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'exception',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 222,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 224,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 224,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 224,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 224,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 224,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 226,
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
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 226,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 226,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 226,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 226,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 226,
                'char' => 48,
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
                                'value' => 'the \'response\' service',
                                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                                'line' => 228,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                              'line' => 228,
                              'char' => 75,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 228,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 228,
                        'char' => 76,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'BaseDispatcher',
                            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                            'line' => 230,
                            'char' => 13,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'EXCEPTION_NO_DI',
                            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                            'line' => 230,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 230,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 230,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 230,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 231,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 233,
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
                  'variable' => 'response',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ResponseInterface',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 233,
                      'char' => 74,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 233,
                        'char' => 54,
                      ),
                      'name' => 'getShared',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'response',
                            'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                            'line' => 233,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 233,
                          'char' => 73,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 233,
                      'char' => 74,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 233,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 233,
                  'char' => 74,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 238,
              'char' => 16,
            ),
            4 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'response',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 238,
                  'char' => 18,
                ),
                'name' => 'setStatusCode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '404',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 238,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 238,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Not Found',
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 238,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 238,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 238,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 243,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'exception',
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
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 243,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 243,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'exceptionCode',
                          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                          'line' => 243,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 243,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 243,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 243,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 245,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 245,
                    'char' => 17,
                  ),
                  'name' => 'handleException',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'exception',
                        'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                        'line' => 245,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                      'line' => 245,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 245,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 245,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 245,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                    'line' => 246,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                  'line' => 247,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 252,
              'char' => 13,
            ),
            7 => 
            array (
              'type' => 'throw',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'exception',
                'file' => '/app/phalcon/Mvc/Dispatcher.zep',
                'line' => 252,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Mvc/Dispatcher.zep',
              'line' => 253,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Throws an internal exception
     *',
          'file' => '/app/phalcon/Mvc/Dispatcher.zep',
          'line' => 220,
          'last-line' => 254,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Dispatcher.zep',
      'line' => 40,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Dispatcher.zep',
    'line' => 40,
    'char' => 5,
  ),
);