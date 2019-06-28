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
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Application',
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
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
        'name' => 'Phalcon\\Application\\Exception',
        'file' => '/app/phalcon/Application/AbstractApplication.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
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
        'file' => '/app/phalcon/Application/AbstractApplication.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
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
        'file' => '/app/phalcon/Application/AbstractApplication.zep',
        'line' => 15,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
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
        'name' => 'Phalcon\\Events\\EventsAwareInterface',
        'file' => '/app/phalcon/Application/AbstractApplication.zep',
        'line' => 16,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Application/AbstractApplication.zep',
        'line' => 17,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
    'line' => 21,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Base class for Phalcon\\Cli\\Console and Phalcon\\Mvc\\Application.
 *',
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
    'line' => 22,
    'char' => 8,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'AbstractApplication',
    'abstract' => 1,
    'final' => 0,
    'extends' => 'Injectable',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'EventsAwareInterface',
        'file' => '/app/phalcon/Application/AbstractApplication.zep',
        'line' => 23,
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
     * @var DiInterface
     *',
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 31,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultModule',
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 36,
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
     * @var null | ManagerInterface
     *',
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 41,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'modules',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 42,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 46,
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
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 47,
                'char' => 55,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 47,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 47,
              'char' => 63,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Application/AbstractApplication.zep',
                    'line' => 49,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 49,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 49,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 49,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'container',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Application/AbstractApplication.zep',
                        'line' => 50,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Application/AbstractApplication.zep',
                      'line' => 50,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 51,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 52,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\AbstractApplication constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 48,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 47,
          'last-line' => 56,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaultModule',
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
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 59,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'defaultModule',
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 59,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 59,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 60,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the default module name
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
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 58,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 58,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 57,
          'last-line' => 64,
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
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 67,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'eventsManager',
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 67,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 67,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 68,
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
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 66,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 66,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 66,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 65,
          'last-line' => 72,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModule',
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
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 73,
              'char' => 43,
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
                  'variable' => 'module',
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 75,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 77,
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
                      'value' => 'module',
                      'file' => '/app/phalcon/Application/AbstractApplication.zep',
                      'line' => 77,
                      'char' => 56,
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
                          'file' => '/app/phalcon/Application/AbstractApplication.zep',
                          'line' => 77,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'modules',
                          'file' => '/app/phalcon/Application/AbstractApplication.zep',
                          'line' => 77,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Application/AbstractApplication.zep',
                        'line' => 77,
                        'char' => 49,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Application/AbstractApplication.zep',
                        'line' => 77,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Application/AbstractApplication.zep',
                      'line' => 77,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Application/AbstractApplication.zep',
                    'line' => 77,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 77,
                  'char' => 56,
                ),
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 77,
                'char' => 56,
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
                              'value' => 'Module \'',
                              'file' => '/app/phalcon/Application/AbstractApplication.zep',
                              'line' => 79,
                              'char' => 26,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Application/AbstractApplication.zep',
                              'line' => 79,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Application/AbstractApplication.zep',
                            'line' => 79,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\' isn\'t registered in the application container',
                            'file' => '/app/phalcon/Application/AbstractApplication.zep',
                            'line' => 80,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Application/AbstractApplication.zep',
                          'line' => 80,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Application/AbstractApplication.zep',
                        'line' => 80,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Application/AbstractApplication.zep',
                    'line' => 80,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 81,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 83,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'module',
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 83,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the module definition registered in the application via module name
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
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 73,
                'char' => 54,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 74,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 74,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 73,
          'last-line' => 88,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModules',
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
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 91,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'modules',
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 91,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 91,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 92,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the modules registered in the application
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
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 90,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 89,
          'last-line' => 96,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'handle',
          'docblock' => '**
     * Handles a request
     *',
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 97,
          'last-line' => 116,
          'char' => 28,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'registerModules',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'modules',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 117,
              'char' => 50,
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
                'value' => 'false',
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 117,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 117,
              'char' => 70,
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
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 119,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'modules',
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
                                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                                'line' => 120,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'modules',
                                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                                'line' => 120,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Application/AbstractApplication.zep',
                              'line' => 120,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Application/AbstractApplication.zep',
                            'line' => 120,
                            'char' => 58,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'modules',
                              'file' => '/app/phalcon/Application/AbstractApplication.zep',
                              'line' => 120,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Application/AbstractApplication.zep',
                            'line' => 120,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Application/AbstractApplication.zep',
                        'line' => 120,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Application/AbstractApplication.zep',
                      'line' => 120,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 121,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'modules',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'modules',
                        'file' => '/app/phalcon/Application/AbstractApplication.zep',
                        'line' => 122,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Application/AbstractApplication.zep',
                      'line' => 122,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 123,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 125,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 125,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 126,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Register an array of modules present in the application
     *
     * ```php
     * $this->registerModules(
     *     [
     *         "frontend" => [
     *             "className" => \\Multiple\\Frontend\\Module::class,
     *             "path"      => "../apps/frontend/Module.php",
     *         ],
     *         "backend" => [
     *             "className" => \\Multiple\\Backend\\Module::class,
     *             "path"      => "../apps/backend/Module.php",
     *         ],
     *     ]
     * );
     * ```
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
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 118,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 118,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 118,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 117,
          'last-line' => 130,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultModule',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultModule',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 131,
              'char' => 59,
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
                  'property' => 'defaultModule',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultModule',
                    'file' => '/app/phalcon/Application/AbstractApplication.zep',
                    'line' => 133,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 133,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 135,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 135,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 136,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the module name to be used if the router doesn\'t return a valid module
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
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 132,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 132,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 132,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 131,
          'last-line' => 140,
          'char' => 19,
        ),
        8 => 
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
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 141,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 141,
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
                    'file' => '/app/phalcon/Application/AbstractApplication.zep',
                    'line' => 143,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 143,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 145,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 145,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Application/AbstractApplication.zep',
              'line' => 146,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the events manager
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
                  'file' => '/app/phalcon/Application/AbstractApplication.zep',
                  'line' => 142,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Application/AbstractApplication.zep',
                'line' => 142,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Application/AbstractApplication.zep',
            'line' => 142,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Application/AbstractApplication.zep',
          'line' => 141,
          'last-line' => 147,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Application/AbstractApplication.zep',
      'line' => 22,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Application/AbstractApplication.zep',
    'line' => 22,
    'char' => 14,
  ),
);