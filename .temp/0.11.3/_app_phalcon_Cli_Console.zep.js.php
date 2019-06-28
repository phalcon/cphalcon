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
    'file' => '/app/phalcon/Cli/Console.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cli',
    'file' => '/app/phalcon/Cli/Console.zep',
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
        'name' => 'Phalcon\\Application\\AbstractApplication',
        'file' => '/app/phalcon/Cli/Console.zep',
        'line' => 13,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Cli/Console.zep',
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
        'name' => 'Phalcon\\Cli\\Router\\Route',
        'file' => '/app/phalcon/Cli/Console.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Cli/Console.zep',
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
        'name' => 'Phalcon\\Cli\\Console\\Exception',
        'file' => '/app/phalcon/Cli/Console.zep',
        'line' => 15,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Cli/Console.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Cli/Console.zep',
        'line' => 16,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Cli/Console.zep',
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
        'file' => '/app/phalcon/Cli/Console.zep',
        'line' => 17,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Cli/Console.zep',
    'line' => 21,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This component allows to create CLI applications using Phalcon
 *',
    'file' => '/app/phalcon/Cli/Console.zep',
    'line' => 22,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Console',
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
          'name' => 'arguments',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Cli/Console.zep',
            'line' => 27,
            'char' => 29,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Cli/Console.zep',
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
          'name' => 'options',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Cli/Console.zep',
            'line' => 32,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Cli/Console.zep',
          'line' => 36,
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
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 37,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 37,
              'char' => 50,
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
                  'variable' => 'className',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 39,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 39,
                  'char' => 33,
                ),
                2 => 
                array (
                  'variable' => 'dispatcher',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 39,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 39,
                  'char' => 60,
                ),
                4 => 
                array (
                  'variable' => 'module',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 39,
                  'char' => 68,
                ),
                5 => 
                array (
                  'variable' => 'moduleName',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 39,
                  'char' => 80,
                ),
                6 => 
                array (
                  'variable' => 'moduleObject',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 40,
                  'char' => 25,
                ),
                7 => 
                array (
                  'variable' => 'modules',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 40,
                  'char' => 34,
                ),
                8 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 40,
                  'char' => 40,
                ),
                9 => 
                array (
                  'variable' => 'router',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 40,
                  'char' => 48,
                ),
                10 => 
                array (
                  'variable' => 'task',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 40,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 42,
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
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 42,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 42,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 42,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 42,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 44,
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
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 44,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 44,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 44,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 44,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 44,
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
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 46,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 46,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 47,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 47,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 47,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 48,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 50,
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
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 50,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 50,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 50,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 50,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 50,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 50,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 56,
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
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 56,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 56,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 56,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 56,
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 57,
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
                            'value' => 'console:boot',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 57,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 57,
                          'char' => 48,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 57,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 57,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 57,
                      'char' => 58,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 57,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 57,
                    'char' => 66,
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 58,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 59,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 60,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 62,
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
                      'value' => 'Router',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 62,
                      'char' => 59,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 62,
                        'char' => 41,
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
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 62,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 62,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 62,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 62,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 62,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 64,
              'char' => 10,
            ),
            6 => 
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
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 64,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 64,
                        'char' => 28,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 64,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 64,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 64,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'arguments',
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 64,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 64,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 64,
                'char' => 49,
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
                      'value' => 'router',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 65,
                      'char' => 20,
                    ),
                    'name' => 'handle',
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
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 65,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'arguments',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 65,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 65,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 65,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 65,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 66,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                      'value' => 'router',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 67,
                      'char' => 20,
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
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 67,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 67,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 67,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 68,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 73,
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
                  'variable' => 'moduleName',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'router',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 73,
                      'char' => 33,
                    ),
                    'name' => 'getModuleName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 73,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 73,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 75,
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
                  'type' => 'variable',
                  'value' => 'moduleName',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 75,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 75,
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
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 76,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'defaultModule',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 76,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 76,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 76,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 77,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 79,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'moduleName',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 79,
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 80,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 80,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 80,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 80,
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
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 81,
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
                                'value' => 'console:beforeStartModule',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 81,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 81,
                              'char' => 65,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 81,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 81,
                              'char' => 71,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'moduleName',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 81,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 81,
                              'char' => 83,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 81,
                          'char' => 87,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 81,
                          'char' => 95,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 81,
                        'char' => 95,
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
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 82,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 83,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 84,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 86,
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
                      'variable' => 'modules',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 86,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'modules',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 86,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 86,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 86,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 88,
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
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'modules',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 88,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'moduleName',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 88,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 88,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 88,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 88,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 88,
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
                                  'value' => 'Module \'',
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 90,
                                  'char' => 30,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'moduleName',
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 90,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 90,
                                'char' => 43,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\' isn\'t registered in the console container',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 91,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 91,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 91,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 91,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 92,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 94,
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
                      'variable' => 'module',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'modules',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 94,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'moduleName',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 94,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 94,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 94,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 96,
                  'char' => 14,
                ),
                4 => 
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
                          'value' => 'module',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 96,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 96,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 96,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 96,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 96,
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
                              'type' => 'string',
                              'value' => 'Invalid module definition path',
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 97,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 97,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 97,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 98,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 100,
                  'char' => 14,
                ),
                5 => 
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 100,
                        'char' => 52,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'module',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 100,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'className',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 100,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 100,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 100,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 100,
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
                          'variable' => 'className',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'Module',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 101,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 101,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 102,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 104,
                  'char' => 14,
                ),
                6 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 104,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'module',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 104,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'path',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 104,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 104,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 104,
                    'char' => 41,
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
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 105,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 105,
                                'char' => 46,
                              ),
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 105,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 105,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 105,
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
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'Module definition path \'',
                                      'file' => '/app/phalcon/Cli/Console.zep',
                                      'line' => 107,
                                      'char' => 50,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'path',
                                      'file' => '/app/phalcon/Cli/Console.zep',
                                      'line' => 107,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 107,
                                    'char' => 57,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\' doesn\'t exist',
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 108,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 108,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 108,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 108,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 109,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 111,
                      'char' => 18,
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
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 111,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 111,
                              'char' => 43,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'false',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 111,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 111,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 111,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 111,
                        'char' => 52,
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
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 112,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 113,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 114,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 116,
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
                      'variable' => 'moduleObject',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 116,
                          'char' => 42,
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
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 116,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 116,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 116,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 116,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 118,
                  'char' => 24,
                ),
                8 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'moduleObject',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 118,
                      'char' => 26,
                    ),
                    'name' => 'registerAutoloaders',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 118,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 119,
                  'char' => 24,
                ),
                9 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'moduleObject',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 119,
                      'char' => 26,
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
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 119,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 119,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 119,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 121,
                  'char' => 14,
                ),
                10 => 
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 121,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 121,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 121,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 121,
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
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 122,
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
                                'value' => 'console:afterStartModule',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 122,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 122,
                              'char' => 64,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 122,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 122,
                              'char' => 70,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'moduleObject',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 122,
                                'char' => 84,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 122,
                              'char' => 84,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 122,
                          'char' => 88,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 122,
                          'char' => 96,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 122,
                        'char' => 96,
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
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 123,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 124,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 125,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 127,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 129,
              'char' => 11,
            ),
            10 => 
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
                      'value' => 'Dispatcher',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 129,
                      'char' => 71,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 129,
                        'char' => 49,
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
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 129,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 129,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 129,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 129,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 129,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 131,
              'char' => 18,
            ),
            11 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 131,
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 131,
                        'char' => 42,
                      ),
                      'name' => 'getModuleName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 131,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 131,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 131,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 132,
              'char' => 18,
            ),
            12 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 132,
                  'char' => 20,
                ),
                'name' => 'setTaskName',
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 132,
                        'char' => 40,
                      ),
                      'name' => 'getTaskName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 132,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 132,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 132,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 133,
              'char' => 18,
            ),
            13 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 133,
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 133,
                        'char' => 42,
                      ),
                      'name' => 'getActionName',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 133,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 133,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 133,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 134,
              'char' => 18,
            ),
            14 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 134,
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 134,
                        'char' => 38,
                      ),
                      'name' => 'getParams',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 134,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 134,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 134,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 135,
              'char' => 18,
            ),
            15 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'dispatcher',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 135,
                  'char' => 20,
                ),
                'name' => 'setOptions',
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 135,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 135,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 135,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 135,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 135,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 137,
              'char' => 10,
            ),
            16 => 
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
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 137,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 137,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 137,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 137,
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 138,
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
                            'value' => 'console:beforeHandleTask',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 138,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 138,
                          'char' => 60,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 138,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 138,
                          'char' => 66,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'dispatcher',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 138,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 138,
                          'char' => 78,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 138,
                      'char' => 82,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 138,
                      'char' => 90,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 138,
                    'char' => 90,
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
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 139,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 140,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 141,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 143,
              'char' => 11,
            ),
            17 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'task',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dispatcher',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 143,
                      'char' => 31,
                    ),
                    'name' => 'dispatch',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 143,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 143,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 145,
              'char' => 10,
            ),
            18 => 
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
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 145,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 145,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 145,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 145,
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
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 146,
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
                          'value' => 'console:afterHandleTask',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 146,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 146,
                        'char' => 56,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 146,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 146,
                        'char' => 62,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'task',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 146,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 146,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 146,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 147,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 149,
              'char' => 14,
            ),
            19 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'task',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 149,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 150,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Handle the whole command-line tasks
     *',
          'file' => '/app/phalcon/Cli/Console.zep',
          'line' => 37,
          'last-line' => 154,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setArgument',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 155,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 155,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'str',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 155,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 155,
              'char' => 74,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'shift',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 155,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 155,
              'char' => 94,
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
                  'variable' => 'arg',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 157,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'pos',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 157,
                  'char' => 21,
                ),
                2 => 
                array (
                  'variable' => 'args',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 157,
                  'char' => 27,
                ),
                3 => 
                array (
                  'variable' => 'opts',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 157,
                  'char' => 33,
                ),
                4 => 
                array (
                  'variable' => 'handleArgs',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 157,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 159,
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
                  'variable' => 'args',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 159,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 159,
                  'char' => 22,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'opts',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 160,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 160,
                  'char' => 22,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'handleArgs',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 161,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 161,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 163,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'shift',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 163,
                  'char' => 19,
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
                        'value' => 'arguments',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 163,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 163,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 163,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 163,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_shift',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 164,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 164,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 164,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 165,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 167,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'arguments',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 167,
                'char' => 30,
              ),
              'value' => 'arg',
              'reverse' => 0,
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
                        'value' => 'arg',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 168,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 168,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 168,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 168,
                    'char' => 37,
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
                          'type' => 'fcall',
                          'name' => 'strncmp',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'arg',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 169,
                                'char' => 31,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 169,
                              'char' => 31,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '--',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 169,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 169,
                              'char' => 35,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'int',
                                'value' => '2',
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 169,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 169,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 169,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 169,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 169,
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
                              'variable' => 'pos',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'strpos',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'arg',
                                      'file' => '/app/phalcon/Cli/Console.zep',
                                      'line' => 170,
                                      'char' => 41,
                                    ),
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 170,
                                    'char' => 41,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '=',
                                      'file' => '/app/phalcon/Cli/Console.zep',
                                      'line' => 170,
                                      'char' => 44,
                                    ),
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 170,
                                    'char' => 44,
                                  ),
                                ),
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 170,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 170,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 172,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'pos',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 172,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'opts',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'trim',
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
                                                  'value' => 'arg',
                                                  'file' => '/app/phalcon/Cli/Console.zep',
                                                  'line' => 173,
                                                  'char' => 49,
                                                ),
                                                'file' => '/app/phalcon/Cli/Console.zep',
                                                'line' => 173,
                                                'char' => 49,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '2',
                                                  'file' => '/app/phalcon/Cli/Console.zep',
                                                  'line' => 173,
                                                  'char' => 52,
                                                ),
                                                'file' => '/app/phalcon/Cli/Console.zep',
                                                'line' => 173,
                                                'char' => 52,
                                              ),
                                              2 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'sub',
                                                  'left' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'pos',
                                                    'file' => '/app/phalcon/Cli/Console.zep',
                                                    'line' => 173,
                                                    'char' => 58,
                                                  ),
                                                  'right' => 
                                                  array (
                                                    'type' => 'int',
                                                    'value' => '2',
                                                    'file' => '/app/phalcon/Cli/Console.zep',
                                                    'line' => 173,
                                                    'char' => 61,
                                                  ),
                                                  'file' => '/app/phalcon/Cli/Console.zep',
                                                  'line' => 173,
                                                  'char' => 61,
                                                ),
                                                'file' => '/app/phalcon/Cli/Console.zep',
                                                'line' => 173,
                                                'char' => 61,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Cli/Console.zep',
                                            'line' => 173,
                                            'char' => 62,
                                          ),
                                          'file' => '/app/phalcon/Cli/Console.zep',
                                          'line' => 173,
                                          'char' => 62,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Cli/Console.zep',
                                      'line' => 173,
                                      'char' => 63,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'trim',
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
                                                'value' => 'arg',
                                                'file' => '/app/phalcon/Cli/Console.zep',
                                                'line' => 173,
                                                'char' => 82,
                                              ),
                                              'file' => '/app/phalcon/Cli/Console.zep',
                                              'line' => 173,
                                              'char' => 82,
                                            ),
                                            1 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'add',
                                                'left' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'pos',
                                                  'file' => '/app/phalcon/Cli/Console.zep',
                                                  'line' => 173,
                                                  'char' => 88,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '1',
                                                  'file' => '/app/phalcon/Cli/Console.zep',
                                                  'line' => 173,
                                                  'char' => 91,
                                                ),
                                                'file' => '/app/phalcon/Cli/Console.zep',
                                                'line' => 173,
                                                'char' => 91,
                                              ),
                                              'file' => '/app/phalcon/Cli/Console.zep',
                                              'line' => 173,
                                              'char' => 91,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Cli/Console.zep',
                                          'line' => 173,
                                          'char' => 92,
                                        ),
                                        'file' => '/app/phalcon/Cli/Console.zep',
                                        'line' => 173,
                                        'char' => 92,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 173,
                                    'char' => 93,
                                  ),
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 173,
                                  'char' => 93,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 174,
                              'char' => 21,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'opts',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'trim',
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
                                                  'value' => 'arg',
                                                  'file' => '/app/phalcon/Cli/Console.zep',
                                                  'line' => 175,
                                                  'char' => 49,
                                                ),
                                                'file' => '/app/phalcon/Cli/Console.zep',
                                                'line' => 175,
                                                'char' => 49,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '2',
                                                  'file' => '/app/phalcon/Cli/Console.zep',
                                                  'line' => 175,
                                                  'char' => 52,
                                                ),
                                                'file' => '/app/phalcon/Cli/Console.zep',
                                                'line' => 175,
                                                'char' => 52,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Cli/Console.zep',
                                            'line' => 175,
                                            'char' => 53,
                                          ),
                                          'file' => '/app/phalcon/Cli/Console.zep',
                                          'line' => 175,
                                          'char' => 53,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Cli/Console.zep',
                                      'line' => 175,
                                      'char' => 54,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 175,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 175,
                                  'char' => 62,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 176,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 177,
                          'char' => 17,
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
                              'type' => 'fcall',
                              'name' => 'strncmp',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'arg',
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 178,
                                    'char' => 35,
                                  ),
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 178,
                                  'char' => 35,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '-',
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 178,
                                    'char' => 38,
                                  ),
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 178,
                                  'char' => 38,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 178,
                                    'char' => 41,
                                  ),
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 178,
                                  'char' => 41,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 178,
                              'char' => 44,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 178,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 178,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'opts',
                                  'index-expr' => 
                                  array (
                                    0 => 
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
                                            'value' => 'arg',
                                            'file' => '/app/phalcon/Cli/Console.zep',
                                            'line' => 179,
                                            'char' => 44,
                                          ),
                                          'file' => '/app/phalcon/Cli/Console.zep',
                                          'line' => 179,
                                          'char' => 44,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'int',
                                            'value' => '1',
                                            'file' => '/app/phalcon/Cli/Console.zep',
                                            'line' => 179,
                                            'char' => 47,
                                          ),
                                          'file' => '/app/phalcon/Cli/Console.zep',
                                          'line' => 179,
                                          'char' => 47,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Cli/Console.zep',
                                      'line' => 179,
                                      'char' => 48,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 179,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 179,
                                  'char' => 56,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 180,
                              'char' => 21,
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
                                  'assign-type' => 'variable-append',
                                  'operator' => 'assign',
                                  'variable' => 'args',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'arg',
                                    'file' => '/app/phalcon/Cli/Console.zep',
                                    'line' => 181,
                                    'char' => 41,
                                  ),
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 181,
                                  'char' => 41,
                                ),
                              ),
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 182,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 183,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 184,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'args',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'arg',
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 185,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 185,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 186,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 187,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 189,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'str',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 189,
                'char' => 16,
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
                      'property' => 'arguments',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'implode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Route',
                              'dynamic' => 0,
                              'name' => 'getDelimiter',
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 191,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 191,
                            'char' => 38,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'args',
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 193,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 193,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 193,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 193,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 194,
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
                          'value' => 'args',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 195,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 195,
                        'char' => 26,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 195,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'handleArgs',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'task',
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 196,
                              'char' => 36,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'array_shift',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'args',
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 196,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 196,
                                'char' => 56,
                              ),
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 196,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 196,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 197,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 199,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
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
                          'value' => 'args',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 199,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 199,
                        'char' => 26,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 199,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'handleArgs',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'action',
                              'file' => '/app/phalcon/Cli/Console.zep',
                              'line' => 200,
                              'char' => 38,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'array_shift',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'args',
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 200,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 200,
                                'char' => 58,
                              ),
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 200,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 200,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 201,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 203,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
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
                          'value' => 'args',
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 203,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 203,
                        'char' => 26,
                      ),
                    ),
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 203,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'handleArgs',
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
                                  'type' => 'variable',
                                  'value' => 'handleArgs',
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 204,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 204,
                                'char' => 56,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'args',
                                  'file' => '/app/phalcon/Cli/Console.zep',
                                  'line' => 204,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Cli/Console.zep',
                                'line' => 204,
                                'char' => 62,
                              ),
                            ),
                            'file' => '/app/phalcon/Cli/Console.zep',
                            'line' => 204,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Cli/Console.zep',
                          'line' => 204,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 205,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 207,
                  'char' => 15,
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
                      'property' => 'arguments',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'handleArgs',
                        'file' => '/app/phalcon/Cli/Console.zep',
                        'line' => 207,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Cli/Console.zep',
                      'line' => 207,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 208,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 210,
              'char' => 11,
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
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'opts',
                    'file' => '/app/phalcon/Cli/Console.zep',
                    'line' => 210,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 210,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 212,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 212,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Cli/Console.zep',
              'line' => 213,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set an specific argument
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
                  'value' => 'Console',
                  'file' => '/app/phalcon/Cli/Console.zep',
                  'line' => 156,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cli/Console.zep',
                'line' => 156,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cli/Console.zep',
            'line' => 156,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cli/Console.zep',
          'line' => 155,
          'last-line' => 214,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Cli/Console.zep',
      'line' => 22,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Cli/Console.zep',
    'line' => 22,
    'char' => 5,
  ),
);