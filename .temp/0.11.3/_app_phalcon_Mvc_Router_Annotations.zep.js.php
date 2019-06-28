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
    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Router',
    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
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
        'name' => 'Phalcon\\Mvc\\Router',
        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
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
        'name' => 'Phalcon\\Annotations\\Annotation',
        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
        'line' => 15,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\Exception',
        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
    'line' => 39,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Router\\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 * ```php
 * use Phalcon\\Mvc\\Router\\Annotations;
 *
 * $di->setShared(
 *     "router",
 *     function() {
 *         // Use the annotations router
 *         $router = new Annotations(false);
 *
 *         // This will do the same as above but only if the handled uri starts with /robots
 *         $router->addResource("Robots", "/robots");
 *
 *         return $router;
 *     }
 * );
 * ```
 *',
    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
    'line' => 40,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Annotations',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Router',
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
          'name' => 'actionSuffix',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Action',
            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
            'line' => 42,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
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
          'name' => 'controllerSuffix',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Controller',
            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
            'line' => 44,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
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
          'name' => 'handlers',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
            'line' => 46,
            'char' => 28,
          ),
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 48,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'routePrefix',
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 54,
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
          'name' => 'addModuleResource',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'module',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 55,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 55,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'prefix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 55,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 55,
              'char' => 93,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'handlers',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 57,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 57,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handler',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 57,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 57,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'module',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 57,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 57,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 57,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 57,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 59,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 59,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 60,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a resource to the annotations handler
     * A resource is a class that contains routing annotations
     * The class is located in a module
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
                  'value' => 'Annotations',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 56,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 56,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
            'line' => 56,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 55,
          'last-line' => 65,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addResource',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 66,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'prefix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 66,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 66,
              'char' => 71,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'handlers',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 68,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 68,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handler',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 68,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 68,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 68,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 68,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 70,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 70,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 71,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a resource to the annotations handler
     * A resource is a class that contains routing annotations
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
                  'value' => 'Annotations',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 67,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 66,
          'last-line' => 75,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getResources',
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
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 78,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'handlers',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 78,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 78,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 79,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the registered resources
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
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 77,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
            'line' => 77,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 76,
          'last-line' => 83,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 84,
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
                  'variable' => 'annotationsService',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 86,
                  'char' => 31,
                ),
                1 => 
                array (
                  'variable' => 'handlers',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 86,
                  'char' => 41,
                ),
                2 => 
                array (
                  'variable' => 'controllerSuffix',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 86,
                  'char' => 59,
                ),
                3 => 
                array (
                  'variable' => 'scope',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 86,
                  'char' => 66,
                ),
                4 => 
                array (
                  'variable' => 'prefix',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 86,
                  'char' => 74,
                ),
                5 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 87,
                  'char' => 22,
                ),
                6 => 
                array (
                  'variable' => 'handler',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 87,
                  'char' => 31,
                ),
                7 => 
                array (
                  'variable' => 'controllerName',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 87,
                  'char' => 47,
                ),
                8 => 
                array (
                  'variable' => 'lowerControllerName',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 87,
                  'char' => 68,
                ),
                9 => 
                array (
                  'variable' => 'namespaceName',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 88,
                  'char' => 26,
                ),
                10 => 
                array (
                  'variable' => 'moduleName',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 88,
                  'char' => 38,
                ),
                11 => 
                array (
                  'variable' => 'handlerAnnotations',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 88,
                  'char' => 58,
                ),
                12 => 
                array (
                  'variable' => 'classAnnotations',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 88,
                  'char' => 76,
                ),
                13 => 
                array (
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 89,
                  'char' => 24,
                ),
                14 => 
                array (
                  'variable' => 'annotation',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 89,
                  'char' => 36,
                ),
                15 => 
                array (
                  'variable' => 'methodAnnotations',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 89,
                  'char' => 55,
                ),
                16 => 
                array (
                  'variable' => 'method',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 89,
                  'char' => 63,
                ),
                17 => 
                array (
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 89,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 90,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'sufixed',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 90,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 92,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 92,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 92,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 92,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 92,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 92,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 92,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 94,
              'char' => 10,
            ),
            3 => 
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
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 94,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 94,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 94,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 94,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 94,
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
                                'value' => 'the \'annotations\' service',
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 96,
                                'char' => 78,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 96,
                              'char' => 78,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 97,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 97,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 97,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 98,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 100,
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
                  'variable' => 'annotationsService',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 100,
                      'char' => 44,
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
                          'value' => 'annotations',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 100,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 100,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 100,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 100,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 102,
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
                  'variable' => 'handlers',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 102,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handlers',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 102,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 102,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 102,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 104,
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
                  'variable' => 'controllerSuffix',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 104,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'controllerSuffix',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 104,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 104,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 104,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 106,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'handlers',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 106,
                'char' => 31,
              ),
              'value' => 'scope',
              'reverse' => 0,
              'statements' => 
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
                        'value' => 'scope',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 107,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 107,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 107,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 107,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 109,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 114,
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
                      'variable' => 'prefix',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'scope',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 114,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 114,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 114,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 114,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 116,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 116,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 116,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 116,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'starts_with',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'uri',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 116,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 116,
                            'char' => 49,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'prefix',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 116,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 116,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 116,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 116,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 116,
                    'char' => 59,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 118,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 123,
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
                      'variable' => 'handler',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'scope',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 123,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 123,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 123,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 123,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 125,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'memstr',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handler',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 125,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 125,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '\\\\',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 125,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 125,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 125,
                    'char' => 36,
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
                          'variable' => 'controllerName',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'get_class_ns',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'handler',
                                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                  'line' => 131,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 131,
                                'char' => 58,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 131,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 131,
                          'char' => 59,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'namespaceName',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'get_ns_class',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'handler',
                                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                  'line' => 132,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 132,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 132,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 132,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 133,
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
                          'variable' => 'controllerName',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handler',
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 134,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 134,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 136,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'fetch',
                      'expr' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'namespaceName',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 136,
                          'char' => 60,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 136,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultNamespace',
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 136,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 136,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 136,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 137,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 139,
                  'char' => 15,
                ),
                5 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'routePrefix',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 139,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 139,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 144,
                  'char' => 17,
                ),
                6 => 
                array (
                  'type' => 'fetch',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'moduleName',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 144,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'scope',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 144,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '2',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 144,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 144,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 144,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 146,
                  'char' => 15,
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
                      'variable' => 'sufixed',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'controllerName',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 146,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'controllerSuffix',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 146,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 146,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 146,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 151,
                  'char' => 14,
                ),
                8 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'namespaceName',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 151,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 151,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 151,
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
                          'variable' => 'sufixed',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'namespaceName',
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 152,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\\\\',
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 152,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 152,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sufixed',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 152,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 152,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 152,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 153,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 158,
                  'char' => 15,
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
                      'variable' => 'handlerAnnotations',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'annotationsService',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 158,
                          'char' => 57,
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
                              'value' => 'sufixed',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 158,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 158,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 158,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 158,
                      'char' => 70,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 160,
                  'char' => 14,
                ),
                10 => 
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
                        'value' => 'handlerAnnotations',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 160,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 160,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 160,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 160,
                    'char' => 52,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 162,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 167,
                  'char' => 15,
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
                      'variable' => 'classAnnotations',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handlerAnnotations',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 167,
                          'char' => 55,
                        ),
                        'name' => 'getClassAnnotations',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 167,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 167,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 169,
                  'char' => 14,
                ),
                12 => 
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
                        'value' => 'classAnnotations',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 169,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 169,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 169,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 169,
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
                          'variable' => 'annotations',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'classAnnotations',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 170,
                              'char' => 52,
                            ),
                            'name' => 'getAnnotations',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 170,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 170,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 172,
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
                            'value' => 'annotations',
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 172,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 172,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 172,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 172,
                        'char' => 48,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'annotations',
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 173,
                            'char' => 51,
                          ),
                          'value' => 'annotation',
                          'reverse' => 0,
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
                                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                  'line' => 174,
                                  'char' => 30,
                                ),
                                'name' => 'processControllerAnnotation',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'controllerName',
                                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                      'line' => 175,
                                      'char' => 43,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                    'line' => 175,
                                    'char' => 43,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'annotation',
                                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                      'line' => 177,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                    'line' => 177,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 177,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 178,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 179,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 180,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 185,
                  'char' => 15,
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
                      'variable' => 'methodAnnotations',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handlerAnnotations',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 185,
                          'char' => 56,
                        ),
                        'name' => 'getMethodsAnnotations',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 185,
                        'char' => 80,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 185,
                      'char' => 80,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 187,
                  'char' => 14,
                ),
                14 => 
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
                        'value' => 'methodAnnotations',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 187,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 187,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 187,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 187,
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
                          'variable' => 'lowerControllerName',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'uncamelize',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'controllerName',
                                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                  'line' => 188,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 188,
                                'char' => 68,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 188,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 188,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 190,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'methodAnnotations',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 190,
                        'char' => 61,
                      ),
                      'key' => 'method',
                      'value' => 'collection',
                      'reverse' => 0,
                      'statements' => 
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
                                'value' => 'collection',
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 191,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 191,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'object',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 191,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 191,
                            'char' => 52,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'continue',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 193,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 195,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 195,
                              'char' => 50,
                            ),
                            'name' => 'getAnnotations',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 195,
                            'char' => 68,
                          ),
                          'value' => 'annotation',
                          'reverse' => 0,
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
                                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                  'line' => 196,
                                  'char' => 30,
                                ),
                                'name' => 'processActionAnnotation',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'moduleName',
                                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                      'line' => 197,
                                      'char' => 39,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                    'line' => 197,
                                    'char' => 39,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'namespaceName',
                                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                      'line' => 198,
                                      'char' => 42,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                    'line' => 198,
                                    'char' => 42,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'lowerControllerName',
                                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                      'line' => 199,
                                      'char' => 48,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                    'line' => 199,
                                    'char' => 48,
                                  ),
                                  3 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'method',
                                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                      'line' => 200,
                                      'char' => 35,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                    'line' => 200,
                                    'char' => 35,
                                  ),
                                  4 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'annotation',
                                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                      'line' => 202,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                    'line' => 202,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 202,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 203,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 204,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 205,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 206,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 211,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'handle',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 211,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 211,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 211,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 212,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Produce the routing parameters from the rewrite information
     *',
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 84,
          'last-line' => 216,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'processActionAnnotation',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'module',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 217,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'namespaceName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 217,
              'char' => 82,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'controller',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 217,
              'char' => 102,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'action',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 217,
              'char' => 118,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'annotation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Annotation',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 218,
                'char' => 31,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 218,
              'char' => 32,
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 220,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'actionName',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 220,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'routePrefix',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 220,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'paths',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 220,
                  'char' => 49,
                ),
                4 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 220,
                  'char' => 56,
                ),
                5 => 
                array (
                  'variable' => 'uri',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 220,
                  'char' => 61,
                ),
                6 => 
                array (
                  'variable' => 'route',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 220,
                  'char' => 68,
                ),
                7 => 
                array (
                  'variable' => 'methods',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 220,
                  'char' => 77,
                ),
                8 => 
                array (
                  'variable' => 'converts',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 221,
                  'char' => 21,
                ),
                9 => 
                array (
                  'variable' => 'param',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 221,
                  'char' => 28,
                ),
                10 => 
                array (
                  'variable' => 'convert',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 221,
                  'char' => 37,
                ),
                11 => 
                array (
                  'variable' => 'conversorParam',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 221,
                  'char' => 53,
                ),
                12 => 
                array (
                  'variable' => 'routeName',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 221,
                  'char' => 64,
                ),
                13 => 
                array (
                  'variable' => 'beforeMatch',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 221,
                  'char' => 77,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 222,
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
                  'variable' => 'isRoute',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 222,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 224,
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
                  'variable' => 'isRoute',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 224,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 224,
                  'char' => 28,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'methods',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 225,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 225,
                  'char' => 27,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotation',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 226,
                      'char' => 31,
                    ),
                    'name' => 'getName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 226,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 226,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 231,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'name',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 231,
                'char' => 21,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'Route',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 232,
                    'char' => 23,
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
                          'variable' => 'isRoute',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 233,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 233,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 234,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 236,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 236,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'Get',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 236,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 237,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'Post',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 237,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 238,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'Put',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 238,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 239,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'Patch',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 239,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 240,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'Delete',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 240,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 241,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'Options',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 241,
                    'char' => 25,
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
                          'variable' => 'isRoute',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 242,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 242,
                          'char' => 35,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'methods',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'strtoupper',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                  'line' => 243,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 243,
                                'char' => 46,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 243,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 243,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 244,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 245,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 245,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 247,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'isRoute',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 247,
                  'char' => 21,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 247,
                'char' => 21,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 249,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 251,
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
                  'variable' => 'actionName',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtolower',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'str_replace',
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
                                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                  'line' => 251,
                                  'char' => 54,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'actionSuffix',
                                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                  'line' => 251,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 251,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 251,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '',
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 251,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 251,
                              'char' => 69,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'action',
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 251,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 251,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 251,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 251,
                        'char' => 78,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 251,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 251,
                  'char' => 79,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'routePrefix',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 252,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'routePrefix',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 252,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 252,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 252,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 257,
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
                  'variable' => 'paths',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotation',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 257,
                      'char' => 32,
                    ),
                    'name' => 'getNamedArgument',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'paths',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 257,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 257,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 257,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 257,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 259,
              'char' => 10,
            ),
            7 => 
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
                    'value' => 'paths',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 259,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 259,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 259,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
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
                      'variable' => 'paths',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 260,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 260,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 261,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 266,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'module',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 266,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 266,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 266,
                'char' => 26,
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
                      'variable' => 'paths',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'module',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 267,
                          'char' => 29,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'module',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 267,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 267,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 268,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 273,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'namespaceName',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 273,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 273,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 273,
                'char' => 33,
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
                      'variable' => 'paths',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'namespace',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 274,
                          'char' => 32,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'namespaceName',
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 274,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 274,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 275,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 277,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'paths',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'controller',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 277,
                      'char' => 29,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'controller',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 277,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 277,
                  'char' => 43,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'paths',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'action',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 278,
                      'char' => 25,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'actionName',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 278,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 278,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 280,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotation',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 280,
                      'char' => 32,
                    ),
                    'name' => 'getArgument',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 280,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 280,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 280,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 280,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 285,
              'char' => 10,
            ),
            12 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 285,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 285,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 285,
                'char' => 27,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 286,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '/',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 286,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 286,
                    'char' => 27,
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
                          'variable' => 'uri',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'routePrefix',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 287,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 287,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 287,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 287,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 288,
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
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'routePrefix',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 289,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 289,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 289,
                        'char' => 41,
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
                              'variable' => 'uri',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'routePrefix',
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 290,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 290,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 291,
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
                              'variable' => 'uri',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                                'line' => 292,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 292,
                              'char' => 36,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 293,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 294,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 295,
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
                      'variable' => 'uri',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'routePrefix',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 296,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'actionName',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 296,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 296,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 296,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 297,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 302,
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
                  'variable' => 'route',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 302,
                      'char' => 26,
                    ),
                    'name' => 'add',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'uri',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 302,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 302,
                        'char' => 34,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paths',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 302,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 302,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 302,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 302,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 307,
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
                  'value' => 'methods',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 307,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 307,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 307,
                'char' => 29,
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
                      'variable' => 'methods',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'annotation',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 308,
                          'char' => 38,
                        ),
                        'name' => 'getNamedArgument',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'methods',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 308,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 308,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 308,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 308,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 309,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 311,
              'char' => 10,
            ),
            15 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'methods',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 311,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 311,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 311,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 311,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'methods',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 311,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 311,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 311,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 311,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 311,
                'char' => 64,
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
                      'value' => 'route',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 312,
                      'char' => 19,
                    ),
                    'name' => 'via',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'methods',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 312,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 312,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 312,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 313,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 318,
              'char' => 11,
            ),
            16 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'converts',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotation',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 318,
                      'char' => 35,
                    ),
                    'name' => 'getNamedArgument',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'converts',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 318,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 318,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 318,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 318,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 320,
              'char' => 10,
            ),
            17 => 
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
                    'value' => 'converts',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 320,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 320,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 320,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 320,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'converts',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 321,
                    'char' => 44,
                  ),
                  'key' => 'param',
                  'value' => 'convert',
                  'reverse' => 0,
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
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 322,
                          'char' => 23,
                        ),
                        'name' => 'convert',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'param',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 322,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 322,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'convert',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 322,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 322,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 322,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 323,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 324,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 329,
              'char' => 11,
            ),
            18 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'converts',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotation',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 329,
                      'char' => 35,
                    ),
                    'name' => 'getNamedArgument',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'conversors',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 329,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 329,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 329,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 329,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 331,
              'char' => 10,
            ),
            19 => 
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
                    'value' => 'converts',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 331,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 331,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 331,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 331,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'converts',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 332,
                    'char' => 53,
                  ),
                  'key' => 'conversorParam',
                  'value' => 'convert',
                  'reverse' => 0,
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
                          'value' => 'route',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 333,
                          'char' => 23,
                        ),
                        'name' => 'convert',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'conversorParam',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 333,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 333,
                            'char' => 46,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'convert',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 333,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 333,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 333,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 334,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 335,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 340,
              'char' => 11,
            ),
            20 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'beforeMatch',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotation',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 340,
                      'char' => 38,
                    ),
                    'name' => 'getNamedArgument',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'beforeMatch',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 340,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 340,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 340,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 340,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 342,
              'char' => 10,
            ),
            21 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'beforeMatch',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 342,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 342,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 342,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 342,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'beforeMatch',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 342,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 342,
                    'char' => 63,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 342,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 342,
                  'char' => 72,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 342,
                'char' => 72,
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
                      'value' => 'route',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 343,
                      'char' => 19,
                    ),
                    'name' => 'beforeMatch',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'beforeMatch',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 343,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 343,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 343,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 344,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 346,
              'char' => 11,
            ),
            22 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'routeName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotation',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 346,
                      'char' => 36,
                    ),
                    'name' => 'getNamedArgument',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 346,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 346,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 346,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 346,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 348,
              'char' => 10,
            ),
            23 => 
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
                    'value' => 'routeName',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 348,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 348,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 348,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 348,
                'char' => 39,
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
                      'value' => 'route',
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 349,
                      'char' => 19,
                    ),
                    'name' => 'setName',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'routeName',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 349,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 349,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 349,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 350,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 352,
              'char' => 14,
            ),
            24 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 352,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 353,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks for annotations in the public methods of the controller
     *',
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 217,
          'last-line' => 357,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'processControllerAnnotation',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 358,
              'char' => 64,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'annotation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Annotation',
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 358,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 358,
              'char' => 89,
            ),
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'annotation',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 363,
                    'char' => 23,
                  ),
                  'name' => 'getName',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 363,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'RoutePrefix',
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 363,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                'line' => 363,
                'char' => 49,
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
                      'property' => 'routePrefix',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'annotation',
                          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                          'line' => 364,
                          'char' => 48,
                        ),
                        'name' => 'getArgument',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                              'line' => 364,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                            'line' => 364,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                        'line' => 364,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                      'line' => 364,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 365,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 366,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks for annotations in the controller docblock
     *',
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 358,
          'last-line' => 370,
          'char' => 19,
        ),
        6 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 371,
              'char' => 57,
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
                  'property' => 'actionSuffix',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'actionSuffix',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 373,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 373,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 374,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Changes the action method suffix
     *',
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 371,
          'last-line' => 378,
          'char' => 19,
        ),
        7 => 
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
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 379,
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
                  'property' => 'controllerSuffix',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'controllerSuffix',
                    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                    'line' => 381,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
                  'line' => 381,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
              'line' => 382,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Changes the controller class suffix
     *',
          'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
          'line' => 379,
          'last-line' => 383,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
      'line' => 40,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Router/Annotations.zep',
    'line' => 40,
    'char' => 5,
  ),
);