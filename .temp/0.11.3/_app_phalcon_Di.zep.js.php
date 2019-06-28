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
    'file' => '/app/phalcon/Di.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Config\\Config',
        'file' => '/app/phalcon/Di.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Di\\Service',
        'file' => '/app/phalcon/Di.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'file' => '/app/phalcon/Di.zep',
        'line' => 15,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Di\\Exception',
        'file' => '/app/phalcon/Di.zep',
        'line' => 16,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Di\\Exception\\ServiceResolutionException',
        'file' => '/app/phalcon/Di.zep',
        'line' => 17,
        'char' => 52,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Config\\Adapter\\Php',
        'file' => '/app/phalcon/Di.zep',
        'line' => 18,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Config\\Adapter\\Yaml',
        'file' => '/app/phalcon/Di.zep',
        'line' => 19,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Di\\ServiceInterface',
        'file' => '/app/phalcon/Di.zep',
        'line' => 20,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Di.zep',
        'line' => 21,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Di.zep',
        'line' => 22,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
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
        'name' => 'Phalcon\\Di\\ServiceProviderInterface',
        'file' => '/app/phalcon/Di.zep',
        'line' => 23,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Di.zep',
    'line' => 62,
    'char' => 2,
  ),
  13 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Di is a component that implements Dependency Injection/Service
 * Location of services and it\'s itself a container for them.
 *
 * Since Phalcon is highly decoupled, Phalcon\\Di is essential to integrate the
 * different components of the framework. The developer can also use this
 * component to inject dependencies and manage global instances of the different
 * classes used in the application.
 *
 * Basically, this component implements the `Inversion of Control` pattern.
 * Applying this, the objects do not receive their dependencies using setters or
 * constructors, but requesting a service dependency injector. This reduces the
 * overall complexity, since there is only one way to get the required
 * dependencies within a component.
 *
 * Additionally, this pattern increases testability in the code, thus making it
 * less prone to errors.
 *
 *```php
 * use Phalcon\\Di;
 * use Phalcon\\Http\\Request;
 *
 * $di = new Di();
 *
 * // Using a string definition
 * $di->set("request", Request::class, true);
 *
 * // Using an anonymous function
 * $di->setShared(
 *     "request",
 *     function () {
 *         return new Request();
 *     }
 * );
 *
 * $request = $di->getRequest();
 *```
 *',
    'file' => '/app/phalcon/Di.zep',
    'line' => 63,
    'char' => 5,
  ),
  14 => 
  array (
    'type' => 'class',
    'name' => 'Di',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'DiInterface',
        'file' => '/app/phalcon/Di.zep',
        'line' => 64,
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
          'name' => 'services',
          'docblock' => '**
     * List of registered services
     *',
          'file' => '/app/phalcon/Di.zep',
          'line' => 72,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sharedInstances',
          'docblock' => '**
     * List of shared instances
     *',
          'file' => '/app/phalcon/Di.zep',
          'line' => 79,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'eventsManager',
          'docblock' => '**
     * Events Manager
     *
     * @var ManagerInterface
     *',
          'file' => '/app/phalcon/Di.zep',
          'line' => 84,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => '_default',
          'docblock' => '**
     * Latest DI build
     *',
          'file' => '/app/phalcon/Di.zep',
          'line' => 89,
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
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 92,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_default',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 92,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 92,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 92,
                'char' => 28,
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
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => '_default',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 93,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 93,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 94,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Di constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 91,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 90,
          'last-line' => 99,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__call',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 100,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Di.zep',
                'line' => 100,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 100,
              'char' => 64,
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
                  'variable' => 'instance',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 102,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'possibleService',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 102,
                  'char' => 38,
                ),
                2 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 102,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 108,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
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
                      'value' => 'method',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 108,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 108,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'get',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 108,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 108,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 108,
                'char' => 37,
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
                      'variable' => 'possibleService',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'lcfirst',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
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
                                    'value' => 'method',
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 109,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 109,
                                  'char' => 56,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '3',
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 109,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 109,
                                  'char' => 59,
                                ),
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 109,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 109,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 109,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 109,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 111,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 111,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'services',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 111,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 111,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'possibleService',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 111,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 111,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 111,
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
                          'variable' => 'instance',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 112,
                              'char' => 37,
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
                                  'value' => 'possibleService',
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 112,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 112,
                                'char' => 57,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'arguments',
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 112,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 112,
                                'char' => 68,
                              ),
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 112,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 112,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 114,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'instance',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 114,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 115,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 116,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 122,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
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
                      'value' => 'method',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 122,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 122,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'set',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 122,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 122,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 122,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 123,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'arguments',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 123,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 123,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 123,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 123,
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
                          'value' => 'this',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 124,
                          'char' => 22,
                        ),
                        'name' => 'set',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'lcfirst',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
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
                                          'value' => 'method',
                                          'file' => '/app/phalcon/Di.zep',
                                          'line' => 126,
                                          'char' => 38,
                                        ),
                                        'file' => '/app/phalcon/Di.zep',
                                        'line' => 126,
                                        'char' => 38,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'int',
                                          'value' => '3',
                                          'file' => '/app/phalcon/Di.zep',
                                          'line' => 126,
                                          'char' => 41,
                                        ),
                                        'file' => '/app/phalcon/Di.zep',
                                        'line' => 126,
                                        'char' => 41,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 127,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 127,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 127,
                              'char' => 22,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 127,
                            'char' => 22,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'definition',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 129,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 129,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 129,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 131,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 131,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 132,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 133,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 138,
              'char' => 13,
            ),
            3 => 
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
                          'value' => 'Call to undefined method or service \'',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 139,
                          'char' => 51,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 139,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 139,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '\'',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 140,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 140,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 140,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 140,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 141,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic method to get or set services using setters/getters
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
                'file' => '/app/phalcon/Di.zep',
                'line' => 100,
                'char' => 73,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 101,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 101,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 100,
          'last-line' => 147,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'attempt',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 148,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 148,
              'char' => 53,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'shared',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Di.zep',
                'line' => 148,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 148,
              'char' => 74,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 150,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'services',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 150,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 150,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 150,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 150,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 150,
                'char' => 39,
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
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 151,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 152,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 154,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'services',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 154,
                      'char' => 32,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Service',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'definition',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 154,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 154,
                        'char' => 58,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'shared',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 154,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 154,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 154,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 154,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 156,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 156,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 156,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 156,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 156,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 156,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 157,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Attempts to register a service in the services container
     * Only is successful if a service hasn\'t been registered previously
     * with the same name
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 148,
                  'char' => 98,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 148,
                'char' => 98,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 149,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 149,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 148,
          'last-line' => 161,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 162,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di.zep',
                'line' => 162,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 162,
              'char' => 56,
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
                  'variable' => 'service',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 164,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 164,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'isShared',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 164,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'instance',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 164,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 164,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 170,
              'char' => 10,
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
                  'value' => 'service',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 170,
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
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 170,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'services',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 170,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 170,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 170,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 170,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 170,
                'char' => 48,
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
                      'variable' => 'isShared',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'service',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 171,
                          'char' => 36,
                        ),
                        'name' => 'isShared',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 171,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 171,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 173,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'isShared',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 173,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 173,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'sharedInstances',
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 173,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 173,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 173,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 173,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 173,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 173,
                    'char' => 62,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 174,
                            'char' => 29,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'sharedInstances',
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 174,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 174,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 174,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 174,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 175,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 176,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 178,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ManagerInterface',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 178,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 178,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 178,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 178,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 178,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 178,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 184,
              'char' => 10,
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 184,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 184,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 184,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 184,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'instance',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 185,
                          'char' => 42,
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
                              'value' => 'di:beforeServiceResolve',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 186,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 186,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 187,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 187,
                            'char' => 21,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'name',
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 189,
                                    'char' => 25,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'name',
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 189,
                                    'char' => 37,
                                  ),
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 189,
                                  'char' => 37,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'parameters',
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 190,
                                    'char' => 31,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'parameters',
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 191,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 191,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 192,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 192,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 192,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 192,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 193,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 195,
              'char' => 10,
            ),
            4 => 
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
                    'value' => 'instance',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 195,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 195,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 195,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 195,
                'char' => 38,
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
                      'type' => 'variable',
                      'value' => 'service',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 196,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 196,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 196,
                    'char' => 33,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'try-catch',
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
                              'variable' => 'instance',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'service',
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 199,
                                  'char' => 44,
                                ),
                                'name' => 'resolve',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'parameters',
                                      'file' => '/app/phalcon/Di.zep',
                                      'line' => 199,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 199,
                                    'char' => 63,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Di.zep',
                                      'line' => 199,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 199,
                                    'char' => 69,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 199,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 199,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 200,
                          'char' => 17,
                        ),
                      ),
                      'catches' => 
                      array (
                        0 => 
                        array (
                          'classes' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'ServiceResolutionException',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 200,
                              'char' => 52,
                            ),
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
                                          'value' => 'Service \'',
                                          'file' => '/app/phalcon/Di.zep',
                                          'line' => 202,
                                          'char' => 35,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'name',
                                          'file' => '/app/phalcon/Di.zep',
                                          'line' => 202,
                                          'char' => 42,
                                        ),
                                        'file' => '/app/phalcon/Di.zep',
                                        'line' => 202,
                                        'char' => 42,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\' cannot be resolved',
                                        'file' => '/app/phalcon/Di.zep',
                                        'line' => 203,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Di.zep',
                                      'line' => 203,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 203,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 203,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 204,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 207,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 207,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'isShared',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 207,
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
                              'assign-type' => 'object-property-array-index',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'sharedInstances',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 208,
                                  'char' => 51,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'instance',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 208,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 208,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 209,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 210,
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
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 215,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 215,
                                'char' => 47,
                              ),
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 215,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 215,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 215,
                        'char' => 49,
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
                                      'value' => 'Service \'',
                                      'file' => '/app/phalcon/Di.zep',
                                      'line' => 217,
                                      'char' => 35,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'name',
                                      'file' => '/app/phalcon/Di.zep',
                                      'line' => 217,
                                      'char' => 42,
                                    ),
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 217,
                                    'char' => 42,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\' wasn\'t found in the dependency injection container',
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 218,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di.zep',
                                  'line' => 218,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 218,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 218,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 219,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 221,
                      'char' => 18,
                    ),
                    1 => 
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 221,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 221,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 221,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 221,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'count',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 221,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 221,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 221,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 221,
                        'char' => 68,
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
                              'variable' => 'instance',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'create_instance_params',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'name',
                                      'file' => '/app/phalcon/Di.zep',
                                      'line' => 222,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 222,
                                    'char' => 63,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'parameters',
                                      'file' => '/app/phalcon/Di.zep',
                                      'line' => 222,
                                      'char' => 75,
                                    ),
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 222,
                                    'char' => 75,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 222,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 222,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 223,
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
                              'variable' => 'instance',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'create_instance',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'name',
                                      'file' => '/app/phalcon/Di.zep',
                                      'line' => 224,
                                      'char' => 56,
                                    ),
                                    'file' => '/app/phalcon/Di.zep',
                                    'line' => 224,
                                    'char' => 56,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 224,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 224,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 225,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 226,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 227,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 233,
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
                    'value' => 'instance',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 233,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 233,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 233,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 233,
                'char' => 38,
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
                      'value' => 'instance',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 234,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'InjectionAwareInterface',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 234,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 234,
                    'char' => 60,
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
                          'value' => 'instance',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 235,
                          'char' => 26,
                        ),
                        'name' => 'setDI',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 235,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 235,
                            'char' => 37,
                          ),
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 235,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 236,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 237,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 243,
              'char' => 10,
            ),
            6 => 
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
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 243,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 243,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 243,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 243,
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
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 244,
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
                          'value' => 'di:afterServiceResolve',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 245,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 245,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 246,
                          'char' => 21,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 246,
                        'char' => 21,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'key' => 
                              array (
                                'type' => 'string',
                                'value' => 'name',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 248,
                                'char' => 25,
                              ),
                              'value' => 
                              array (
                                'type' => 'variable',
                                'value' => 'name',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 248,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 248,
                              'char' => 37,
                            ),
                            1 => 
                            array (
                              'key' => 
                              array (
                                'type' => 'string',
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 249,
                                'char' => 31,
                              ),
                              'value' => 
                              array (
                                'type' => 'variable',
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 249,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 249,
                              'char' => 43,
                            ),
                            2 => 
                            array (
                              'key' => 
                              array (
                                'type' => 'string',
                                'value' => 'instance',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 250,
                                'char' => 29,
                              ),
                              'value' => 
                              array (
                                'type' => 'variable',
                                'value' => 'instance',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 251,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 251,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 252,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 252,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 252,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 253,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 255,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'instance',
                'file' => '/app/phalcon/Di.zep',
                'line' => 255,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 256,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resolves the service based on its configuration
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
                'file' => '/app/phalcon/Di.zep',
                'line' => 163,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 163,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 162,
          'last-line' => 260,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getDefault',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'static-property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'self',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 263,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => '_default',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 263,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 263,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 264,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the latest DI created
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
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 261,
                  'char' => 58,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 261,
                'char' => 58,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 262,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 262,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 261,
          'last-line' => 268,
          'char' => 26,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getInternalEventsManager',
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
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 271,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'eventsManager',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 271,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 271,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 272,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal event manager
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 270,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 270,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 270,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 269,
          'last-line' => 276,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRaw',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 277,
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
                  'variable' => 'service',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 279,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 281,
              'char' => 10,
            ),
            1 => 
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
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'service',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 281,
                      'char' => 58,
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
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 281,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'services',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 281,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 281,
                        'char' => 51,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 281,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 281,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 281,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 281,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 281,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Service \'',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 283,
                              'char' => 27,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 283,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 283,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\' wasn\'t found in the dependency injection container',
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 284,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 284,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 284,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 284,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 285,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 287,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'service',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 287,
                  'char' => 24,
                ),
                'name' => 'getDefinition',
                'call-type' => 1,
                'file' => '/app/phalcon/Di.zep',
                'line' => 287,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 288,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a service definition without resolving
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
                'file' => '/app/phalcon/Di.zep',
                'line' => 278,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 278,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 277,
          'last-line' => 292,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getService',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 293,
              'char' => 44,
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
                  'variable' => 'service',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 295,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 297,
              'char' => 10,
            ),
            1 => 
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
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'service',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 297,
                      'char' => 58,
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
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 297,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'services',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 297,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 297,
                        'char' => 51,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 297,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 297,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 297,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 297,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 297,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Service \'',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 299,
                              'char' => 27,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 299,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 299,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\' wasn\'t found in the dependency injection container',
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 300,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 300,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 300,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 300,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 301,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 303,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'service',
                'file' => '/app/phalcon/Di.zep',
                'line' => 303,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 304,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a Phalcon\\Di\\Service instance
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 294,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 294,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 294,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 293,
          'last-line' => 308,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getServices',
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
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 311,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'services',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 311,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 311,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 312,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the services registered in the DI
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 310,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Di.zep',
                'line' => 310,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 310,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 309,
          'last-line' => 317,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getShared',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 318,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di.zep',
                'line' => 318,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 318,
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
                  'variable' => 'instance',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 320,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 323,
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
                    'value' => 'instance',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 323,
                    'char' => 57,
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
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 323,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'sharedInstances',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 323,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 323,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 323,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 323,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 323,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 323,
                'char' => 57,
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
                      'variable' => 'instance',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 325,
                          'char' => 33,
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
                              'value' => 'name',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 325,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 325,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 325,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 325,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 325,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 325,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 328,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'sharedInstances',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 328,
                          'char' => 43,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'instance',
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 328,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 328,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 329,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 331,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'instance',
                'file' => '/app/phalcon/Di.zep',
                'line' => 331,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 332,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resolves a service, the resolved service is stored in the DI, subsequent
     * requests for this service will return the same instance
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
                'file' => '/app/phalcon/Di.zep',
                'line' => 319,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 319,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 318,
          'last-line' => 336,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'loadFromConfig',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'config',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Config',
                'file' => '/app/phalcon/Di.zep',
                'line' => 337,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 337,
              'char' => 54,
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
                  'variable' => 'services',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 339,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 339,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'service',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 339,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 341,
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
                  'variable' => 'services',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 341,
                      'char' => 31,
                    ),
                    'name' => 'toArray',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 341,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 341,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 343,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'services',
                'file' => '/app/phalcon/Di.zep',
                'line' => 343,
                'char' => 39,
              ),
              'key' => 'name',
              'value' => 'service',
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
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 344,
                      'char' => 18,
                    ),
                    'name' => 'set',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 345,
                          'char' => 21,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 345,
                        'char' => 21,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'service',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 346,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 346,
                        'char' => 24,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'and',
                          'left' => 
                          array (
                            'type' => 'isset',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'service',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 347,
                                'char' => 30,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'shared',
                                'file' => '/app/phalcon/Di.zep',
                                'line' => 347,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 347,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 347,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'service',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 347,
                              'char' => 49,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'shared',
                              'file' => '/app/phalcon/Di.zep',
                              'line' => 347,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Di.zep',
                            'line' => 348,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 348,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 348,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 348,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 349,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 350,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Loads services from a Config object.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 338,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 337,
          'last-line' => 383,
          'char' => 22,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'loadFromPhp',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 384,
              'char' => 49,
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
                  'variable' => 'services',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 386,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 388,
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
                  'variable' => 'services',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Php',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filePath',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 388,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 388,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 388,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 388,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 390,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 390,
                  'char' => 14,
                ),
                'name' => 'loadFromConfig',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'services',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 390,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 390,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 390,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 391,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Loads services from a php config file.
     *
     * ```php
     * $di->loadFromPhp("path/services.php");
     * ```
     *
     * And the services can be specified in the file as:
     *
     * ```php
     * return [
     *      \'myComponent\' => [
     *          \'className\' => \'\\Acme\\Components\\MyComponent\',
     *          \'shared\' => true,
     *      ],
     *      \'group\' => [
     *          \'className\' => \'\\Acme\\Group\',
     *          \'arguments\' => [
     *              [
     *                  \'type\' => \'service\',
     *                  \'service\' => \'myComponent\',
     *              ],
     *          ],
     *      ],
     *      \'user\' => [
     *          \'className\' => \'\\Acme\\User\',
     *      ],
     * ];
     * ```
     *
     * @link https://docs.phalconphp.com/en/latest/reference/di.html
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 385,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 384,
          'last-line' => 425,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'loadFromYaml',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 426,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'callbacks',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di.zep',
                'line' => 426,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 426,
              'char' => 75,
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
                  'variable' => 'services',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 428,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 430,
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
                  'variable' => 'services',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Yaml',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filePath',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 430,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 430,
                        'char' => 41,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'callbacks',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 430,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 430,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 430,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 430,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 432,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 432,
                  'char' => 14,
                ),
                'name' => 'loadFromConfig',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'services',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 432,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 432,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 432,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 433,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Loads services from a yaml file.
     *
     * ```php
     * $di->loadFromYaml(
     *     "path/services.yaml",
     *     [
     *         "!approot" => function ($value) {
     *             return dirname(__DIR__) . $value;
     *         }
     *     ]
     * );
     * ```
     *
     * And the services can be specified in the file as:
     *
     * ```php
     * myComponent:
     *     className: \\Acme\\Components\\MyComponent
     *     shared: true
     *
     * group:
     *     className: \\Acme\\Group
     *     arguments:
     *         - type: service
     *           name: myComponent
     *
     * user:
     *    className: \\Acme\\User
     * ```
     *
     * @link https://docs.phalconphp.com/en/latest/reference/di.html
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 427,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 426,
          'last-line' => 437,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 438,
              'char' => 37,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 440,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'services',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 440,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 440,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 440,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 440,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 440,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 441,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether the DI contains a service by a name
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
                'file' => '/app/phalcon/Di.zep',
                'line' => 439,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 439,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 438,
          'last-line' => 449,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetGet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 450,
              'char' => 39,
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
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 452,
                  'char' => 21,
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
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 452,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 452,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 452,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 453,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Allows to obtain a shared service using the array syntax
     *
     *```php
     * var_dump($di["request"]);
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
                'file' => '/app/phalcon/Di.zep',
                'line' => 451,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 451,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 450,
          'last-line' => 457,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 458,
              'char' => 42,
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
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 460,
                  'char' => 21,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 460,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 460,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 460,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 461,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a service is registered using the array syntax
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
                'file' => '/app/phalcon/Di.zep',
                'line' => 459,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 459,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 458,
          'last-line' => 469,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetSet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 470,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 470,
              'char' => 55,
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
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 472,
                  'char' => 14,
                ),
                'name' => 'setShared',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 472,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 472,
                    'char' => 29,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 472,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 472,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 472,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 473,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Allows to register a shared service using the array syntax
     *
     *```php
     * $di["request"] = new \\Phalcon\\Http\\Request();
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 471,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 470,
          'last-line' => 477,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetUnset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 478,
              'char' => 41,
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
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 480,
                  'char' => 14,
                ),
                'name' => 'remove',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 480,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 480,
                    'char' => 26,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 480,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 481,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes a service from the services container using the array syntax
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 479,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 478,
          'last-line' => 503,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'register',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'provider',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ServiceProviderInterface',
                'file' => '/app/phalcon/Di.zep',
                'line' => 504,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 504,
              'char' => 65,
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
                  'value' => 'provider',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 506,
                  'char' => 18,
                ),
                'name' => 'register',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 506,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 506,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 506,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 507,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Registers a service provider.
     *
     * ```php
     * use Phalcon\\DiInterface;
     * use Phalcon\\Di\\ServiceProviderInterface;
     *
     * class SomeServiceProvider implements ServiceProviderInterface
     * {
     *     public function register(DiInterface $di)
     *     {
     *         $di->setShared(
     *             \'service\',
     *             function () {
     *                 // ...
     *             }
     *         );
     *     }
     * }
     * ```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 505,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 504,
          'last-line' => 512,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'remove',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 513,
              'char' => 40,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 515,
                    'char' => 20,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 515,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 515,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 515,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 515,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 516,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 516,
                    'char' => 20,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sharedInstances',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 516,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 516,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 516,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 516,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 517,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes a service in the services container
     * It also removes any shared instance created for the service
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 514,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 513,
          'last-line' => 521,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'reset',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => '_default',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 524,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 524,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 525,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resets the internal default DI
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 523,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 522,
          'last-line' => 529,
          'char' => 26,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 530,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 530,
              'char' => 53,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'shared',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Di.zep',
                'line' => 530,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 530,
              'char' => 74,
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
                  'property' => 'services',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 532,
                      'char' => 32,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Service',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'definition',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 532,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 532,
                        'char' => 58,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'shared',
                          'file' => '/app/phalcon/Di.zep',
                          'line' => 532,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Di.zep',
                        'line' => 532,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 532,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 532,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 534,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 534,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 534,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 534,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 534,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 534,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 535,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Registers a service in the services container
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 531,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 531,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 531,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 530,
          'last-line' => 540,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setDefault',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Di.zep',
                'line' => 541,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 541,
              'char' => 62,
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
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => '_default',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 543,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 543,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 544,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a default dependency injection container to be obtained into static
     * methods
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di.zep',
            'line' => 542,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 541,
          'last-line' => 548,
          'char' => 26,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setInternalEventsManager',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventsManager',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ManagerInterface',
                'file' => '/app/phalcon/Di.zep',
                'line' => 549,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 549,
              'char' => 78,
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
                  'property' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 551,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 551,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 552,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the internal event manager
     *',
          'file' => '/app/phalcon/Di.zep',
          'line' => 549,
          'last-line' => 556,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRaw',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 557,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'rawDefinition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ServiceInterface',
                'file' => '/app/phalcon/Di.zep',
                'line' => 557,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 557,
              'char' => 74,
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
                  'property' => 'services',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 559,
                      'char' => 32,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'rawDefinition',
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 559,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 559,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 561,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'rawDefinition',
                'file' => '/app/phalcon/Di.zep',
                'line' => 561,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 562,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a service using a raw Phalcon\\Di\\Service definition
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 558,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 558,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 558,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 557,
          'last-line' => 566,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setShared',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 567,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di.zep',
              'line' => 567,
              'char' => 59,
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
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 569,
                  'char' => 21,
                ),
                'name' => 'set',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 569,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 569,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 569,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 569,
                    'char' => 42,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Di.zep',
                      'line' => 569,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Di.zep',
                    'line' => 569,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Di.zep',
                'line' => 569,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Di.zep',
              'line' => 570,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Registers an "always shared" service in the services container
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di.zep',
                  'line' => 568,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di.zep',
                'line' => 568,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di.zep',
            'line' => 568,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di.zep',
          'line' => 567,
          'last-line' => 571,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Di.zep',
      'line' => 63,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Di.zep',
    'line' => 63,
    'char' => 5,
  ),
);