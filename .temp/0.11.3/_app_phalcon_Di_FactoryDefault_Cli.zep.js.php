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
    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Di\\FactoryDefault',
    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
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
        'name' => 'Phalcon\\Di\\FactoryDefault',
        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
        'line' => 13,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
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
        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
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
        'name' => 'Phalcon\\Filter\\FilterFactory',
        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
        'line' => 15,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
    'line' => 24,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Di\\FactoryDefault\\Cli
 *
 * This is a variant of the standard Phalcon\\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 *',
    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
    'line' => 25,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Cli',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'FactoryDefault',
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
                  'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                  'line' => 32,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
              'line' => 34,
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
                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                'line' => 34,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
              'line' => 36,
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
                    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                    'line' => 36,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                  'line' => 36,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
              'line' => 38,
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
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 39,
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
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 39,
                                'char' => 82,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 39,
                              'char' => 82,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 39,
                                'char' => 88,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 39,
                              'char' => 88,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 39,
                          'char' => 89,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 39,
                        'char' => 89,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'dispatcher',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 40,
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
                                'value' => 'Phalcon\\\\Cli\\\\Dispatcher',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 40,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 40,
                              'char' => 69,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 40,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 40,
                              'char' => 75,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 40,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 40,
                        'char' => 76,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'escaper',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 41,
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
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 41,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 41,
                              'char' => 61,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 41,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 41,
                              'char' => 67,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 41,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 41,
                        'char' => 68,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 42,
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
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 42,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 42,
                              'char' => 69,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 42,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 42,
                              'char' => 75,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 42,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 42,
                        'char' => 76,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'filter',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 43,
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
                                  'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                  'line' => 43,
                                  'char' => 52,
                                ),
                                'name' => 'newInstance',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 43,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 43,
                              'char' => 66,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 43,
                                'char' => 72,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 43,
                              'char' => 72,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 43,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 43,
                        'char' => 73,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'modelsManager',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 44,
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
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 44,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 44,
                              'char' => 73,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 44,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 44,
                              'char' => 79,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 44,
                          'char' => 80,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 44,
                        'char' => 80,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'modelsMetadata',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 45,
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
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 45,
                                'char' => 82,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 45,
                              'char' => 82,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 45,
                                'char' => 88,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 45,
                              'char' => 88,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 45,
                          'char' => 89,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 45,
                        'char' => 89,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'router',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 46,
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
                                'value' => 'Phalcon\\\\Cli\\\\Router',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 46,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 46,
                              'char' => 65,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 46,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 46,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 46,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 46,
                        'char' => 72,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'security',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 47,
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
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 47,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 47,
                              'char' => 62,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 47,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 47,
                              'char' => 68,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 47,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 47,
                        'char' => 69,
                      ),
                      9 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'transactionManager',
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 48,
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
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 48,
                                'char' => 86,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 48,
                              'char' => 86,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                                'line' => 48,
                                'char' => 92,
                              ),
                              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                              'line' => 48,
                              'char' => 92,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                          'line' => 49,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                        'line' => 49,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                    'line' => 49,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
                  'line' => 49,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
              'line' => 50,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Di\\FactoryDefault\\Cli constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
            'line' => 31,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
          'line' => 30,
          'last-line' => 51,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Di/FactoryDefault/Cli.zep',
    'line' => 25,
    'char' => 5,
  ),
);