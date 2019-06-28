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
    'file' => '/app/phalcon/Di/FactoryDefault.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Di',
    'file' => '/app/phalcon/Di/FactoryDefault.zep',
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
        'name' => 'Phalcon\\Filter\\FilterFactory',
        'file' => '/app/phalcon/Di/FactoryDefault.zep',
        'line' => 13,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Di/FactoryDefault.zep',
    'line' => 20,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This is a variant of the standard Phalcon\\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the
 * developer does not need to register each service individually providing a
 * full stack framework
 *',
    'file' => '/app/phalcon/Di/FactoryDefault.zep',
    'line' => 21,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'FactoryDefault',
    'abstract' => 0,
    'final' => 0,
    'extends' => '\\Phalcon\\Di',
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
          'name' => '__construct',
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
                  'variable' => 'filter',
                  'file' => '/app/phalcon/Di/FactoryDefault.zep',
                  'line' => 28,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Di/FactoryDefault.zep',
              'line' => 30,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                'line' => 30,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Di/FactoryDefault.zep',
              'line' => 32,
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
                  'variable' => 'filter',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'FilterFactory',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Di/FactoryDefault.zep',
                    'line' => 32,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Di/FactoryDefault.zep',
                  'line' => 32,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Di/FactoryDefault.zep',
              'line' => 34,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'services',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'annotations',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 35,
                          'char' => 24,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Annotations\\\\Adapter\\\\Memory',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 35,
                                'char' => 82,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 35,
                              'char' => 82,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 35,
                                'char' => 88,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 35,
                              'char' => 88,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 35,
                          'char' => 89,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 35,
                        'char' => 89,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'assets',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 36,
                          'char' => 19,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Assets\\\\Manager',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 36,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 36,
                              'char' => 69,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 36,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 36,
                              'char' => 75,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 36,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 36,
                        'char' => 76,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'crypt',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 37,
                          'char' => 18,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Crypt',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 37,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 37,
                              'char' => 59,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 37,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 37,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 37,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 37,
                        'char' => 66,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'cookies',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 38,
                          'char' => 20,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Http\\\\Response\\\\Cookies',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 38,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 38,
                              'char' => 77,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 38,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 38,
                              'char' => 83,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 38,
                          'char' => 84,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 38,
                        'char' => 84,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'dispatcher',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 39,
                          'char' => 23,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Mvc\\\\Dispatcher',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 39,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 39,
                              'char' => 69,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 39,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 39,
                              'char' => 75,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 39,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 39,
                        'char' => 76,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'escaper',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 40,
                          'char' => 20,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Escaper',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 40,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 40,
                              'char' => 61,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 40,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 40,
                              'char' => 67,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 40,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 40,
                        'char' => 68,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 41,
                          'char' => 26,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Events\\\\Manager',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 41,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 41,
                              'char' => 69,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 41,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 41,
                              'char' => 75,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 41,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 41,
                        'char' => 76,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'flash',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 42,
                          'char' => 18,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Flash\\\\Direct',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 42,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 42,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 42,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 42,
                              'char' => 73,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 42,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 42,
                        'char' => 74,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'flashSession',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 43,
                          'char' => 25,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Flash\\\\Session',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 43,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 43,
                              'char' => 68,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 43,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 43,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 43,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 43,
                        'char' => 75,
                      ),
                      9 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'filter',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 44,
                          'char' => 19,
                        ),
                        'value' => 
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
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filter',
                                  'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                  'line' => 44,
                                  'char' => 52,
                                ),
                                'name' => 'newInstance',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 44,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 44,
                              'char' => 66,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 44,
                                'char' => 72,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 44,
                              'char' => 72,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 44,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 44,
                        'char' => 73,
                      ),
                      10 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'modelsManager',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 45,
                          'char' => 26,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Mvc\\\\Model\\\\Manager',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 45,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 45,
                              'char' => 73,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 45,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 45,
                              'char' => 79,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 45,
                          'char' => 80,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 45,
                        'char' => 80,
                      ),
                      11 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'modelsMetadata',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 46,
                          'char' => 27,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Mvc\\\\Model\\\\MetaData\\\\Memory',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 46,
                                'char' => 82,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 46,
                              'char' => 82,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 46,
                                'char' => 88,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 46,
                              'char' => 88,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 46,
                          'char' => 89,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 46,
                        'char' => 89,
                      ),
                      12 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'request',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 47,
                          'char' => 20,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Http\\\\Request',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 47,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 47,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 47,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 47,
                              'char' => 73,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 47,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 47,
                        'char' => 74,
                      ),
                      13 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'response',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 48,
                          'char' => 21,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Http\\\\Response',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 48,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 48,
                              'char' => 68,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 48,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 48,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 48,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 48,
                        'char' => 75,
                      ),
                      14 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'router',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 49,
                          'char' => 19,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Mvc\\\\Router',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 49,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 49,
                              'char' => 65,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 49,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 49,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 49,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 49,
                        'char' => 72,
                      ),
                      15 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'security',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 50,
                          'char' => 21,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Security',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 50,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 50,
                              'char' => 62,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 50,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 50,
                              'char' => 68,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 50,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 50,
                        'char' => 69,
                      ),
                      16 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'tag',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 51,
                          'char' => 16,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Tag',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 51,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 51,
                              'char' => 57,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 51,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 51,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 51,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 51,
                        'char' => 64,
                      ),
                      17 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'transactionManager',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 52,
                          'char' => 31,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Mvc\\\\Model\\\\Transaction\\\\Manager',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 52,
                                'char' => 86,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 52,
                              'char' => 86,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 52,
                                'char' => 92,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 52,
                              'char' => 92,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 52,
                          'char' => 93,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 52,
                        'char' => 93,
                      ),
                      18 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'url',
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 53,
                          'char' => 16,
                        ),
                        'value' => 
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
                                'type' => 'string',
                                'value' => 'Phalcon\\\\Url',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 53,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 53,
                              'char' => 57,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault.zep',
                                'line' => 53,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault.zep',
                              'line' => 53,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault.zep',
                          'line' => 54,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault.zep',
                        'line' => 54,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/FactoryDefault.zep',
                    'line' => 54,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Di/FactoryDefault.zep',
                  'line' => 54,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Di/FactoryDefault.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Di\\FactoryDefault constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/FactoryDefault.zep',
            'line' => 27,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/FactoryDefault.zep',
          'line' => 26,
          'last-line' => 56,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Di/FactoryDefault.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Di/FactoryDefault.zep',
    'line' => 21,
    'char' => 5,
  ),
);