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
    'file' => '/app/phalcon/Di/Injectable.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Di',
    'file' => '/app/phalcon/Di/Injectable.zep',
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
        'name' => 'Phalcon\\Di',
        'file' => '/app/phalcon/Di/Injectable.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Di/Injectable.zep',
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
        'file' => '/app/phalcon/Di/Injectable.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Di/Injectable.zep',
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
        'file' => '/app/phalcon/Di/Injectable.zep',
        'line' => 15,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Di/Injectable.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Di/Injectable.zep',
        'line' => 16,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Di/Injectable.zep',
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
        'name' => 'Phalcon\\Events\\EventsAwareInterface',
        'file' => '/app/phalcon/Di/Injectable.zep',
        'line' => 17,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Di/Injectable.zep',
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
        'name' => 'Phalcon\\Di\\Exception',
        'file' => '/app/phalcon/Di/Injectable.zep',
        'line' => 18,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Di/Injectable.zep',
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
        'name' => 'Phalcon\\Session\\BagInterface',
        'file' => '/app/phalcon/Di/Injectable.zep',
        'line' => 19,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Di/Injectable.zep',
    'line' => 49,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class allows to access services in the services container by just only
 * accessing a public property with the same name of a registered service
 *
 * @property \\Phalcon\\Mvc\\Dispatcher|\\Phalcon\\Mvc\\DispatcherInterface $dispatcher
 * @property \\Phalcon\\Mvc\\Router|\\Phalcon\\Mvc\\RouterInterface $router
 * @property \\Phalcon\\Url|\\Phalcon\\UrlInterface $url
 * @property \\Phalcon\\Http\\Request|\\Phalcon\\Http\\RequestInterface $request
 * @property \\Phalcon\\Http\\Response|\\Phalcon\\Http\\ResponseInterface $response
 * @property \\Phalcon\\Http\\Response\\Cookies|\\Phalcon\\Http\\Response\\CookiesInterface $cookies
 * @property \\Phalcon\\Filter\\FilterLocator $filter
 * @property \\Phalcon\\Flash\\Direct $flash
 * @property \\Phalcon\\Flash\\Session $flashSession
 * @property \\Phalcon\\Session\\ManagerInterface $session
 * @property \\Phalcon\\Events\\Manager|\\Phalcon\\Events\\ManagerInterface $eventsManager
 * @property \\Phalcon\\Db\\AdapterInterface $db
 * @property \\Phalcon\\Security $security
 * @property \\Phalcon\\Crypt|\\Phalcon\\CryptInterface $crypt
 * @property \\Phalcon\\Tag $tag
 * @property \\Phalcon\\Escaper|\\Phalcon\\EscaperInterface $escaper
 * @property \\Phalcon\\Annotations\\Adapter\\Memory|\\Phalcon\\Annotations\\Adapter $annotations
 * @property \\Phalcon\\Mvc\\Model\\Manager|\\Phalcon\\Mvc\\Model\\ManagerInterface $modelsManager
 * @property \\Phalcon\\Mvc\\Model\\MetaData\\Memory|\\Phalcon\\Mvc\\Model\\MetadataInterface $modelsMetadata
 * @property \\Phalcon\\Mvc\\Model\\Transaction\\Manager|\\Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface $transactionManager
 * @property \\Phalcon\\Assets\\Manager $assets
 * @property \\Phalcon\\Di|\\Phalcon\\DiInterface $di
 * @property \\Phalcon\\Session\\Bag|\\Phalcon\\Session\\BagInterface $persistent
 * @property \\Phalcon\\Mvc\\View|\\Phalcon\\Mvc\\ViewInterface $view
 *',
    'file' => '/app/phalcon/Di/Injectable.zep',
    'line' => 50,
    'char' => 8,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Injectable',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Di/Injectable.zep',
        'line' => 50,
        'char' => 61,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'EventsAwareInterface',
        'file' => '/app/phalcon/Di/Injectable.zep',
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
          'name' => 'container',
          'docblock' => '**
     * Dependency Injector
     *
     * @var DiInterface
     *',
          'file' => '/app/phalcon/Di/Injectable.zep',
          'line' => 63,
          'char' => 6,
        ),
        1 => 
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
     * @var \\Phalcon\\Events\\ManagerInterface
     *',
          'file' => '/app/phalcon/Di/Injectable.zep',
          'line' => 68,
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
          'name' => '__get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'propertyName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 69,
              'char' => 47,
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
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 71,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'service',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 71,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 73,
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
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 73,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 73,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 73,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 73,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 73,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 73,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 75,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'container',
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 75,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 75,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 75,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 75,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Di',
                        'dynamic' => 0,
                        'name' => 'getDefault',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 76,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 76,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 78,
                  'char' => 14,
                ),
                1 => 
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
                          'file' => '/app/phalcon/Di/Injectable.zep',
                          'line' => 78,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 78,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 78,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 78,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 78,
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
                                    'file' => '/app/phalcon/Di/Injectable.zep',
                                    'line' => 80,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Di/Injectable.zep',
                                  'line' => 80,
                                  'char' => 74,
                                ),
                              ),
                              'file' => '/app/phalcon/Di/Injectable.zep',
                              'line' => 81,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Di/Injectable.zep',
                            'line' => 81,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 81,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 82,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 83,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 88,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 88,
                  'char' => 22,
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
                      'value' => 'propertyName',
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 88,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 88,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 88,
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
                      'variable' => 'service',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Di/Injectable.zep',
                          'line' => 89,
                          'char' => 37,
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
                              'value' => 'propertyName',
                              'file' => '/app/phalcon/Di/Injectable.zep',
                              'line' => 89,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Di/Injectable.zep',
                            'line' => 89,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 89,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 89,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 90,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-dynamic-object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'propertyName',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'service',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 90,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 90,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 92,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'service',
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 92,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 95,
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
                  'type' => 'variable',
                  'value' => 'propertyName',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 95,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'di',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 95,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 95,
                'char' => 31,
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
                      'assign-type' => 'string-dynamic-object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'di',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 96,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 96,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 98,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 98,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 99,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 104,
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
                  'type' => 'variable',
                  'value' => 'propertyName',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 104,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'persistent',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 104,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 104,
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
                      'assign-type' => 'string-dynamic-object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'persistent',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'BagInterface',
                          'file' => '/app/phalcon/Di/Injectable.zep',
                          'line' => 110,
                          'char' => 14,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Di/Injectable.zep',
                            'line' => 105,
                            'char' => 63,
                          ),
                          'name' => 'get',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'sessionBag',
                                'file' => '/app/phalcon/Di/Injectable.zep',
                                'line' => 106,
                                'char' => 27,
                              ),
                              'file' => '/app/phalcon/Di/Injectable.zep',
                              'line' => 106,
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
                                      'type' => 'fcall',
                                      'name' => 'get_class',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Di/Injectable.zep',
                                            'line' => 108,
                                            'char' => 35,
                                          ),
                                          'file' => '/app/phalcon/Di/Injectable.zep',
                                          'line' => 108,
                                          'char' => 35,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Di/Injectable.zep',
                                      'line' => 109,
                                      'char' => 17,
                                    ),
                                    'file' => '/app/phalcon/Di/Injectable.zep',
                                    'line' => 109,
                                    'char' => 17,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di/Injectable.zep',
                                'line' => 110,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Di/Injectable.zep',
                              'line' => 110,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Injectable.zep',
                          'line' => 110,
                          'char' => 14,
                        ),
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 110,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 110,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 112,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'property-string-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 112,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'persistent',
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 112,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 112,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 113,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 118,
              'char' => 21,
            ),
            6 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'trigger_error',
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
                        'type' => 'string',
                        'value' => 'Access to undefined property ',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 118,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'propertyName',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 118,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 118,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 118,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 118,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 120,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 120,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 121,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic method __get
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
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 69,
                'char' => 56,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 70,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Injectable.zep',
            'line' => 70,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Injectable.zep',
          'line' => 69,
          'last-line' => 125,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDI',
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
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 128,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 130,
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
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 130,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 130,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 130,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 130,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 132,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'container',
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 132,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 132,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 132,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 132,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Di',
                        'dynamic' => 0,
                        'name' => 'getDefault',
                        'file' => '/app/phalcon/Di/Injectable.zep',
                        'line' => 133,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Di/Injectable.zep',
                      'line' => 133,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 134,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 136,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'container',
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 136,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 137,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal dependency injector
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
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 127,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 127,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Injectable.zep',
            'line' => 127,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Injectable.zep',
          'line' => 126,
          'last-line' => 141,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEventsManager',
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
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 144,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'eventsManager',
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 144,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 144,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 145,
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
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 143,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 143,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Injectable.zep',
            'line' => 143,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Injectable.zep',
          'line' => 142,
          'last-line' => 149,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDI',
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
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 150,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 150,
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 152,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 152,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 153,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the dependency injector
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/Injectable.zep',
            'line' => 151,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Injectable.zep',
          'line' => 150,
          'last-line' => 157,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setEventsManager',
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
                'file' => '/app/phalcon/Di/Injectable.zep',
                'line' => 158,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 158,
              'char' => 70,
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
                    'file' => '/app/phalcon/Di/Injectable.zep',
                    'line' => 160,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Di/Injectable.zep',
                  'line' => 160,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Di/Injectable.zep',
              'line' => 161,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the event manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/Injectable.zep',
            'line' => 159,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Injectable.zep',
          'line' => 158,
          'last-line' => 162,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Di/Injectable.zep',
      'line' => 50,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Di/Injectable.zep',
    'line' => 50,
    'char' => 14,
  ),
);