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
    'file' => '/app/phalcon/Mvc/Application.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'name' => 'Phalcon\\Application\\AbstractApplication',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 15,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'name' => 'Phalcon\\Mvc\\ViewInterface',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 16,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'name' => 'Phalcon\\Mvc\\RouterInterface',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'name' => 'Phalcon\\Http\\ResponseInterface',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 18,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 19,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'name' => 'Phalcon\\Mvc\\DispatcherInterface',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 20,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
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
        'name' => 'Phalcon\\Mvc\\Application\\Exception',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 21,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
    'line' => 22,
    'char' => 3,
  ),
  11 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Router\\RouteInterface',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 22,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
    'line' => 23,
    'char' => 3,
  ),
  12 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\ModuleDefinitionInterface',
        'file' => '/app/phalcon/Mvc/Application.zep',
        'line' => 23,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
    'line' => 70,
    'char' => 2,
  ),
  13 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Application
 *
 * This component encapsulates all the complex operations behind instantiating
 * every component needed and integrating it with the rest to allow the MVC
 * pattern to operate as desired.
 *
 *```php
 * use Phalcon\\Mvc\\Application;
 *
 * class MyApp extends Application
 * {
 *     /**
 *      * Register the services here to make them general or register
 *      * in the ModuleDefinition to make them module-specific
 *      *\\/
 *     protected function registerServices()
 *     {
 *
 *     }
 *
 *     /**
 *      * This method registers all the modules in the application
 *      *\\/
 *     public function main()
 *     {
 *         $this->registerModules(
 *             [
 *                 "frontend" => [
 *                     "className" => "Multiple\\\\Frontend\\\\Module",
 *                     "path"      => "../apps/frontend/Module.php",
 *                 ],
 *                 "backend" => [
 *                     "className" => "Multiple\\\\Backend\\\\Module",
 *                     "path"      => "../apps/backend/Module.php",
 *                 ],
 *             ]
 *         );
 *     }
 * }
 *
 * $application = new MyApp();
 *
 * $application->main();
 *```
 *',
    'file' => '/app/phalcon/Mvc/Application.zep',
    'line' => 71,
    'char' => 5,
  ),
  14 => 
  array (
    'type' => 'class',
    'name' => 'Application',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractApplication',
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
          'name' => 'implicitView',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Mvc/Application.zep',
            'line' => 73,
            'char' => 34,
          ),
          'file' => '/app/phalcon/Mvc/Application.zep',
          'line' => 75,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sendCookies',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Mvc/Application.zep',
            'line' => 75,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Mvc/Application.zep',
          'line' => 77,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sendHeaders',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Mvc/Application.zep',
            'line' => 77,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Mvc/Application.zep',
          'line' => 81,
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
          'name' => 'handle',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 82,
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 84,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 84,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'router',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 84,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'dispatcher',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 84,
                  'char' => 57,
                ),
                4 => 
                array (
                  'variable' => 'response',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 84,
                  'char' => 67,
                ),
                5 => 
                array (
                  'variable' => 'view',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 84,
                  'char' => 73,
                ),
                6 => 
                array (
                  'variable' => 'module',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 85,
                  'char' => 19,
                ),
                7 => 
                array (
                  'variable' => 'moduleObject',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 85,
                  'char' => 33,
                ),
                8 => 
                array (
                  'variable' => 'moduleName',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 85,
                  'char' => 45,
                ),
                9 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 85,
                  'char' => 56,
                ),
                10 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 85,
                  'char' => 62,
                ),
                11 => 
                array (
                  'variable' => 'implicitView',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 85,
                  'char' => 76,
                ),
                12 => 
                array (
                  'variable' => 'returnedResponse',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 86,
                  'char' => 29,
                ),
                13 => 
                array (
                  'variable' => 'controller',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 86,
                  'char' => 41,
                ),
                14 => 
                array (
                  'variable' => 'possibleResponse',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 86,
                  'char' => 59,
                ),
                15 => 
                array (
                  'variable' => 'renderStatus',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 86,
                  'char' => 73,
                ),
                16 => 
                array (
                  'variable' => 'matchedRoute',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 87,
                  'char' => 25,
                ),
                17 => 
                array (
                  'variable' => 'match',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 87,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 89,
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
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 89,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 89,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 89,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 89,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 91,
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
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 91,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 91,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 91,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 91,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 91,
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
                                'value' => 'internal services',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 93,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 93,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 94,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 94,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 94,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 95,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 97,
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
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 97,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 97,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 97,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 97,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 97,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 97,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 103,
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
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 103,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 103,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 103,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 103,
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
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 104,
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
                            'value' => 'application:boot',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 104,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 104,
                          'char' => 52,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 104,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 104,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 104,
                      'char' => 62,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 104,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 104,
                    'char' => 70,
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
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 105,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 106,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 107,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 109,
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
                  'variable' => 'router',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'RouterInterface',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 109,
                      'char' => 68,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 109,
                        'char' => 50,
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
                            'value' => 'router',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 109,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 109,
                          'char' => 67,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 109,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 109,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 109,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 114,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'router',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 114,
                  'char' => 16,
                ),
                'name' => 'handle',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 114,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 114,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 114,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 120,
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
                  'variable' => 'matchedRoute',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'router',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 120,
                      'char' => 35,
                    ),
                    'name' => 'getMatchedRoute',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 120,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 120,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 122,
              'char' => 10,
            ),
            8 => 
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
                    'value' => 'matchedRoute',
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 122,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 122,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 122,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 122,
                'char' => 42,
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
                      'variable' => 'match',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'matchedRoute',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 123,
                          'char' => 38,
                        ),
                        'name' => 'getMatch',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 123,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 123,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 125,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'match',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 125,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 125,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 125,
                    'char' => 31,
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
                          'value' => 'match',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 126,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Closure',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 126,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 126,
                        'char' => 45,
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
                              'variable' => 'match',
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
                                      'value' => 'match',
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 127,
                                      'char' => 52,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 127,
                                    'char' => 52,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'container',
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 127,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 127,
                                    'char' => 63,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 127,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 127,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 128,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 133,
                      'char' => 19,
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
                          'variable' => 'possibleResponse',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'call_user_func_array',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'match',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 134,
                                  'char' => 26,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 134,
                                'char' => 26,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'router',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 135,
                                    'char' => 28,
                                  ),
                                  'name' => 'getParams',
                                  'call-type' => 1,
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 136,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 136,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 136,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 136,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 141,
                      'char' => 18,
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
                            'value' => 'possibleResponse',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 141,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 141,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 141,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 141,
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
                              'variable' => 'response',
                              'expr' => 
                              array (
                                'type' => 'type-hint',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'ResponseInterface',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 142,
                                  'char' => 86,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'container',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 142,
                                    'char' => 66,
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
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 142,
                                        'char' => 85,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 142,
                                      'char' => 85,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 142,
                                  'char' => 86,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 142,
                                'char' => 86,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 142,
                              'char' => 86,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 144,
                          'char' => 28,
                        ),
                        1 => 
                        array (
                          'type' => 'mcall',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'response',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 144,
                              'char' => 30,
                            ),
                            'name' => 'setContent',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'possibleResponse',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 144,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 144,
                                'char' => 58,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 144,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 146,
                          'char' => 26,
                        ),
                        2 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'response',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 146,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 147,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 153,
                      'char' => 18,
                    ),
                    3 => 
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
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'possibleResponse',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 153,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 153,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 153,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 153,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'instanceof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'possibleResponse',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 153,
                            'char' => 83,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ResponseInterface',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 153,
                            'char' => 103,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 153,
                          'char' => 103,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 153,
                        'char' => 103,
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
                              'value' => 'possibleResponse',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 154,
                              'char' => 38,
                            ),
                            'name' => 'sendHeaders',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 154,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 155,
                          'char' => 36,
                        ),
                        1 => 
                        array (
                          'type' => 'mcall',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'possibleResponse',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 155,
                              'char' => 38,
                            ),
                            'name' => 'sendCookies',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 155,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 157,
                          'char' => 26,
                        ),
                        2 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'possibleResponse',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 157,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 158,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 159,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 160,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 165,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'moduleName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'router',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 165,
                      'char' => 33,
                    ),
                    'name' => 'getModuleName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 165,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 165,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 167,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'moduleName',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 167,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 167,
                'char' => 24,
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
                      'variable' => 'moduleName',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 168,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'defaultModule',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 168,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 168,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 168,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 169,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 171,
              'char' => 11,
            ),
            11 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'moduleObject',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 171,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 171,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 176,
              'char' => 10,
            ),
            12 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'moduleName',
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 176,
                'char' => 23,
              ),
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
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 177,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 177,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 177,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 177,
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
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 178,
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
                                'value' => 'application:beforeStartModule',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 178,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 178,
                              'char' => 69,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 178,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 178,
                              'char' => 75,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'moduleName',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 178,
                                'char' => 87,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 178,
                              'char' => 87,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 178,
                          'char' => 91,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 178,
                          'char' => 99,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 178,
                        'char' => 99,
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
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 179,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 180,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 181,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 186,
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
                      'variable' => 'module',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 186,
                          'char' => 31,
                        ),
                        'name' => 'getModule',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'moduleName',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 186,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 186,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 186,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 186,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 191,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'not-equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'module',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 191,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 191,
                            'char' => 41,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 191,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 191,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'not-equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'module',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 191,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 191,
                            'char' => 67,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 191,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 191,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 191,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 191,
                      'char' => 77,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 191,
                    'char' => 77,
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
                              'value' => 'Invalid module definition',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 192,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 192,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 192,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 193,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 199,
                  'char' => 14,
                ),
                3 => 
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
                        'value' => 'module',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 199,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 199,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 199,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 199,
                    'char' => 39,
                  ),
                  'statements' => 
                  array (
                    0 => 
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
                            'value' => 'className',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 203,
                            'char' => 56,
                          ),
                          'right' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'module',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 203,
                              'char' => 44,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'className',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 203,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 203,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 203,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 203,
                        'char' => 56,
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
                              'variable' => 'className',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'Module',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 204,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 204,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 205,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 210,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 210,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'module',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 210,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'path',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 210,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 210,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 210,
                        'char' => 45,
                      ),
                      'statements' => 
                      array (
                        0 => 
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
                                      'value' => 'path',
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 211,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 211,
                                    'char' => 50,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 211,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 211,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 211,
                            'char' => 52,
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
                                          'value' => 'Module definition path \'',
                                          'file' => '/app/phalcon/Mvc/Application.zep',
                                          'line' => 213,
                                          'char' => 54,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'path',
                                          'file' => '/app/phalcon/Mvc/Application.zep',
                                          'line' => 213,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 213,
                                        'char' => 61,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\' doesn\'t exist',
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 214,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 214,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 214,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 214,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 215,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 217,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'not',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'class_exists',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'className',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 217,
                                    'char' => 47,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 217,
                                  'char' => 47,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'false',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 217,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 217,
                                  'char' => 54,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 217,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 217,
                            'char' => 56,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'require',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'path',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 218,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 219,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 220,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 222,
                      'char' => 19,
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
                          'variable' => 'moduleObject',
                          'expr' => 
                          array (
                            'type' => 'type-hint',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ModuleDefinitionInterface',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 222,
                              'char' => 89,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 222,
                                'char' => 74,
                              ),
                              'name' => 'get',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'className',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 222,
                                    'char' => 88,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 222,
                                  'char' => 88,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 222,
                              'char' => 89,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 222,
                            'char' => 89,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 222,
                          'char' => 89,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 228,
                      'char' => 28,
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
                          'value' => 'moduleObject',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 228,
                          'char' => 30,
                        ),
                        'name' => 'registerAutoloaders',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 228,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 228,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 228,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 229,
                      'char' => 28,
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
                          'value' => 'moduleObject',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 229,
                          'char' => 30,
                        ),
                        'name' => 'registerServices',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 229,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 229,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 229,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 230,
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
                        'type' => 'unlikely',
                        'left' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'list',
                            'left' => 
                            array (
                              'type' => 'instanceof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'module',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 234,
                                'char' => 47,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'Closure',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 234,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 234,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 234,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 234,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 234,
                        'char' => 58,
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
                                  'value' => 'Invalid module definition',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 235,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 235,
                                'char' => 66,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 235,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 236,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 238,
                      'char' => 19,
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
                          'variable' => 'moduleObject',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'call_user_func_array',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'module',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 239,
                                  'char' => 27,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 239,
                                'char' => 27,
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
                                        'value' => 'container',
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 242,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 242,
                                      'char' => 21,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 243,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 243,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 243,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 243,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 244,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 249,
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
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 249,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 249,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 249,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 249,
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
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 250,
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
                              'value' => 'application:afterStartModule',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 250,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 250,
                            'char' => 65,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 250,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 250,
                            'char' => 71,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'moduleObject',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 250,
                              'char' => 85,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 250,
                            'char' => 85,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 250,
                        'char' => 86,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 251,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 252,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 257,
              'char' => 11,
            ),
            13 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'implicitView',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 257,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'implicitView',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 257,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 257,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 257,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 259,
              'char' => 10,
            ),
            14 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'implicitView',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 259,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 259,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 259,
                'char' => 34,
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
                      'variable' => 'view',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ViewInterface',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 260,
                          'char' => 66,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 260,
                            'char' => 50,
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
                                'value' => 'view',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 260,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 260,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 260,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 260,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 260,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 261,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 267,
              'char' => 11,
            ),
            15 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'dispatcher',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DispatcherInterface',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 267,
                      'char' => 80,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 267,
                        'char' => 58,
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
                            'value' => 'dispatcher',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 267,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 267,
                          'char' => 79,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 267,
                      'char' => 80,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 267,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 267,
                  'char' => 80,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 269,
              'char' => 18,
            ),
            16 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 269,
                  'char' => 20,
                ),
                'name' => 'setModuleName',
                'call-type' => 1,
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
                        'value' => 'router',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 269,
                        'char' => 42,
                      ),
                      'name' => 'getModuleName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 269,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 269,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 269,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 270,
              'char' => 18,
            ),
            17 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 270,
                  'char' => 20,
                ),
                'name' => 'setNamespaceName',
                'call-type' => 1,
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
                        'value' => 'router',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 270,
                        'char' => 45,
                      ),
                      'name' => 'getNamespaceName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 270,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 270,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 270,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 271,
              'char' => 18,
            ),
            18 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 271,
                  'char' => 20,
                ),
                'name' => 'setControllerName',
                'call-type' => 1,
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
                        'value' => 'router',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 271,
                        'char' => 46,
                      ),
                      'name' => 'getControllerName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 271,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 271,
                    'char' => 66,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 271,
                'char' => 67,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 272,
              'char' => 18,
            ),
            19 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 272,
                  'char' => 20,
                ),
                'name' => 'setActionName',
                'call-type' => 1,
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
                        'value' => 'router',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 272,
                        'char' => 42,
                      ),
                      'name' => 'getActionName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 272,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 272,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 272,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 273,
              'char' => 18,
            ),
            20 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 273,
                  'char' => 20,
                ),
                'name' => 'setParams',
                'call-type' => 1,
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
                        'value' => 'router',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 273,
                        'char' => 38,
                      ),
                      'name' => 'getParams',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 273,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 273,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 273,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 278,
              'char' => 10,
            ),
            21 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'implicitView',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 278,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 278,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 278,
                'char' => 34,
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
                      'value' => 'view',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 279,
                      'char' => 18,
                    ),
                    'name' => 'start',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 279,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 280,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 285,
              'char' => 10,
            ),
            22 => 
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
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 285,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 285,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 285,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 285,
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
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 286,
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
                            'value' => 'application:beforeHandleRequest',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 286,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 286,
                          'char' => 67,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 286,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 286,
                          'char' => 73,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'dispatcher',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 286,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 286,
                          'char' => 85,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 286,
                      'char' => 89,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 286,
                      'char' => 97,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 286,
                    'char' => 97,
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
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 287,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 288,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 289,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 294,
              'char' => 11,
            ),
            23 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'controller',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 294,
                      'char' => 37,
                    ),
                    'name' => 'dispatch',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 294,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 294,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 299,
              'char' => 11,
            ),
            24 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'possibleResponse',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 299,
                      'char' => 43,
                    ),
                    'name' => 'getReturnedValue',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 299,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 299,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 304,
              'char' => 10,
            ),
            25 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'possibleResponse',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 304,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 304,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 304,
                'char' => 39,
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
                      'variable' => 'response',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ResponseInterface',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 305,
                          'char' => 78,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 305,
                            'char' => 58,
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
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 305,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 305,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 305,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 305,
                        'char' => 78,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 305,
                      'char' => 78,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 306,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                        'value' => 'possibleResponse',
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 310,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 310,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 310,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 310,
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
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 311,
                              'char' => 82,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 311,
                                'char' => 62,
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
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 311,
                                    'char' => 81,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 311,
                                  'char' => 81,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 311,
                              'char' => 82,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 311,
                            'char' => 82,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 311,
                          'char' => 82,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 313,
                      'char' => 24,
                    ),
                    1 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'response',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 313,
                          'char' => 26,
                        ),
                        'name' => 'setContent',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'possibleResponse',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 313,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 313,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 313,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 314,
                      'char' => 13,
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
                          'variable' => 'returnedResponse',
                          'expr' => 
                          array (
                            'type' => 'list',
                            'left' => 
                            array (
                              'type' => 'and',
                              'left' => 
                              array (
                                'type' => 'list',
                                'left' => 
                                array (
                                  'type' => 'equals',
                                  'left' => 
                                  array (
                                    'type' => 'typeof',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'possibleResponse',
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 318,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 318,
                                    'char' => 67,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'object',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 318,
                                    'char' => 75,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 318,
                                  'char' => 75,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 318,
                                'char' => 78,
                              ),
                              'right' => 
                              array (
                                'type' => 'list',
                                'left' => 
                                array (
                                  'type' => 'instanceof',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'possibleResponse',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 318,
                                    'char' => 107,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'ResponseInterface',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 318,
                                    'char' => 126,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 318,
                                  'char' => 126,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 318,
                                'char' => 127,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 318,
                              'char' => 127,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 318,
                            'char' => 128,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 318,
                          'char' => 128,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 323,
                      'char' => 18,
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
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 323,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 323,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 323,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 323,
                        'char' => 51,
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
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 324,
                              'char' => 35,
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
                                  'value' => 'application:afterHandleRequest',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 324,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 324,
                                'char' => 71,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 324,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 324,
                                'char' => 77,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'controller',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 324,
                                  'char' => 89,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 324,
                                'char' => 89,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 324,
                            'char' => 90,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 325,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 331,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'returnedResponse',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 331,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 331,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 331,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'implicitView',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 331,
                            'char' => 65,
                          ),
                          'right' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 331,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 331,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 331,
                        'char' => 72,
                      ),
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
                                'value' => 'controller',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 332,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 332,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'object',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 332,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 332,
                            'char' => 52,
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
                                  'variable' => 'renderStatus',
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 333,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 333,
                                  'char' => 48,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 338,
                              'char' => 26,
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
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 338,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 338,
                                  'char' => 50,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'object',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 338,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 338,
                                'char' => 59,
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
                                      'variable' => 'renderStatus',
                                      'expr' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'eventsManager',
                                          'file' => '/app/phalcon/Mvc/Application.zep',
                                          'line' => 339,
                                          'char' => 62,
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
                                              'value' => 'application:viewRender',
                                              'file' => '/app/phalcon/Mvc/Application.zep',
                                              'line' => 339,
                                              'char' => 90,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Application.zep',
                                            'line' => 339,
                                            'char' => 90,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'this',
                                              'file' => '/app/phalcon/Mvc/Application.zep',
                                              'line' => 339,
                                              'char' => 96,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Application.zep',
                                            'line' => 339,
                                            'char' => 96,
                                          ),
                                          2 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'view',
                                              'file' => '/app/phalcon/Mvc/Application.zep',
                                              'line' => 339,
                                              'char' => 102,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Application.zep',
                                            'line' => 339,
                                            'char' => 102,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 339,
                                        'char' => 103,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 339,
                                      'char' => 103,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 340,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 346,
                              'char' => 26,
                            ),
                            2 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'not-identical',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'renderStatus',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 346,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'false',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 346,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 346,
                                'char' => 51,
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
                                      'value' => 'view',
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 352,
                                      'char' => 34,
                                    ),
                                    'name' => 'render',
                                    'call-type' => 1,
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
                                            'value' => 'dispatcher',
                                            'file' => '/app/phalcon/Mvc/Application.zep',
                                            'line' => 353,
                                            'char' => 44,
                                          ),
                                          'name' => 'getControllerName',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Mvc/Application.zep',
                                          'line' => 353,
                                          'char' => 64,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 353,
                                        'char' => 64,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'mcall',
                                          'variable' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'dispatcher',
                                            'file' => '/app/phalcon/Mvc/Application.zep',
                                            'line' => 354,
                                            'char' => 44,
                                          ),
                                          'name' => 'getActionName',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Mvc/Application.zep',
                                          'line' => 355,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 355,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 355,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 356,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 357,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 358,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 363,
                      'char' => 18,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'implicitView',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 363,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 363,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 363,
                        'char' => 42,
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
                              'value' => 'view',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 364,
                              'char' => 26,
                            ),
                            'name' => 'finish',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 364,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 365,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 367,
                      'char' => 18,
                    ),
                    4 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'returnedResponse',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 367,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 367,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 367,
                        'char' => 46,
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
                              'variable' => 'response',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'possibleResponse',
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 372,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 372,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 373,
                          'char' => 17,
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
                              'variable' => 'response',
                              'expr' => 
                              array (
                                'type' => 'type-hint',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'ResponseInterface',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 374,
                                  'char' => 86,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'container',
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 374,
                                    'char' => 66,
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
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 374,
                                        'char' => 85,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 374,
                                      'char' => 85,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 374,
                                  'char' => 86,
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 374,
                                'char' => 86,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 374,
                              'char' => 86,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 376,
                          'char' => 22,
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
                              'value' => 'implicitView',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 376,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'bool',
                              'value' => 'true',
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 376,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Mvc/Application.zep',
                            'line' => 376,
                            'char' => 46,
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
                                  'value' => 'response',
                                  'file' => '/app/phalcon/Mvc/Application.zep',
                                  'line' => 381,
                                  'char' => 34,
                                ),
                                'name' => 'setContent',
                                'call-type' => 1,
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
                                        'value' => 'view',
                                        'file' => '/app/phalcon/Mvc/Application.zep',
                                        'line' => 382,
                                        'char' => 34,
                                      ),
                                      'name' => 'getContent',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Mvc/Application.zep',
                                      'line' => 383,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Application.zep',
                                    'line' => 383,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Application.zep',
                                'line' => 383,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Application.zep',
                              'line' => 384,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 385,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 386,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 387,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 392,
              'char' => 10,
            ),
            26 => 
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
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 392,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 392,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 392,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 392,
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
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 393,
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
                          'value' => 'application:beforeSendResponse',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 393,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 393,
                        'char' => 63,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 393,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 393,
                        'char' => 69,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'response',
                          'file' => '/app/phalcon/Mvc/Application.zep',
                          'line' => 393,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Mvc/Application.zep',
                        'line' => 393,
                        'char' => 79,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 393,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 394,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 399,
              'char' => 10,
            ),
            27 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 399,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'sendHeaders',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 399,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 399,
                'char' => 31,
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
                      'value' => 'response',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 400,
                      'char' => 22,
                    ),
                    'name' => 'sendHeaders',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 400,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 401,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 406,
              'char' => 10,
            ),
            28 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 406,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'sendCookies',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 406,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 406,
                'char' => 30,
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
                      'value' => 'response',
                      'file' => '/app/phalcon/Mvc/Application.zep',
                      'line' => 407,
                      'char' => 22,
                    ),
                    'name' => 'sendCookies',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 407,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 408,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 413,
              'char' => 14,
            ),
            29 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'response',
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 413,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 414,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Handles a MVC request
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
                  'value' => 'ResponseInterface',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 82,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 82,
                'char' => 64,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 83,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Application.zep',
            'line' => 83,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Application.zep',
          'line' => 82,
          'last-line' => 418,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'sendCookiesOnHandleRequest',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sendCookies',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 419,
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
                  'property' => 'sendCookies',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sendCookies',
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 421,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 421,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 423,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 423,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 424,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Enables or disables sending cookies by each request handling
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
                  'value' => 'Application',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 420,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 420,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Application.zep',
            'line' => 420,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Application.zep',
          'line' => 419,
          'last-line' => 429,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'sendHeadersOnHandleRequest',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sendHeaders',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 430,
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
                  'property' => 'sendHeaders',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sendHeaders',
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 432,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 432,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 434,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 434,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 435,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Enables or disables sending headers by each request handling
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
                  'value' => 'Application',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 431,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 431,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Application.zep',
            'line' => 431,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Application.zep',
          'line' => 430,
          'last-line' => 440,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useImplicitView',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'implicitView',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 441,
              'char' => 54,
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
                  'property' => 'implicitView',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'implicitView',
                    'file' => '/app/phalcon/Mvc/Application.zep',
                    'line' => 443,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 443,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 445,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 445,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Application.zep',
              'line' => 446,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * By default. The view is implicitly buffering all the output
     * You can full disable the view component using this method
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
                  'value' => 'Application',
                  'file' => '/app/phalcon/Mvc/Application.zep',
                  'line' => 442,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Application.zep',
                'line' => 442,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Application.zep',
            'line' => 442,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Application.zep',
          'line' => 441,
          'last-line' => 447,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Application.zep',
      'line' => 71,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Application.zep',
    'line' => 71,
    'char' => 5,
  ),
);