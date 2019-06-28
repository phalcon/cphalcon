<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Session/Bag.zep',
    'line' => 10,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Session',
    'file' => '/app/phalcon/Session/Bag.zep',
    'line' => 12,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Collection\\Collection',
        'file' => '/app/phalcon/Session/Bag.zep',
        'line' => 12,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Session/Bag.zep',
    'line' => 13,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Di',
        'file' => '/app/phalcon/Session/Bag.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Session/Bag.zep',
    'line' => 14,
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
        'file' => '/app/phalcon/Session/Bag.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Session/Bag.zep',
    'line' => 15,
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
        'file' => '/app/phalcon/Session/Bag.zep',
        'line' => 15,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Session/Bag.zep',
    'line' => 30,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Session\\Bag
 *
 * This component helps to separate session data into "namespaces". Working by
 * this way you can easily create groups of session variables into the
 * application
 *
 * ```php
 * $user = new \\Phalcon\\Session\\Bag("user");
 *
 * $user->name = "Kimbra Johnson";
 * $user->age  = 22;
 * ```
 *',
    'file' => '/app/phalcon/Session/Bag.zep',
    'line' => 31,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Bag',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Collection',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Session/Bag.zep',
        'line' => 32,
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
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'container',
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 35,
          'char' => 11,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'name',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Session/Bag.zep',
            'line' => 35,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 37,
          'char' => 11,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'session',
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 41,
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 42,
              'char' => 45,
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
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 44,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 44,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 44,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 46,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'name',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 46,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 46,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 48,
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
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Di',
                    'dynamic' => 0,
                    'name' => 'getDefault',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 48,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 48,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 50,
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
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 50,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 50,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 50,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 50,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 50,
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
                                'value' => 'the \'session\' service',
                                'file' => '/app/phalcon/Session/Bag.zep',
                                'line' => 54,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Session/Bag.zep',
                              'line' => 54,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Session/Bag.zep',
                          'line' => 55,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 55,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 55,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 56,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 58,
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
                  'variable' => 'session',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 58,
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
                          'value' => 'session',
                          'file' => '/app/phalcon/Session/Bag.zep',
                          'line' => 58,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 58,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 58,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 58,
                  'char' => 60,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 59,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 59,
                  'char' => 40,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'session',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'session',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 60,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 60,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'session',
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 62,
                      'char' => 28,
                    ),
                    'name' => 'get',
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
                            'file' => '/app/phalcon/Session/Bag.zep',
                            'line' => 62,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'name',
                            'file' => '/app/phalcon/Session/Bag.zep',
                            'line' => 62,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Session/Bag.zep',
                          'line' => 62,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 62,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 62,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 62,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 64,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'data',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 64,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 64,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 64,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 64,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 65,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 65,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 66,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 68,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 68,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 68,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 68,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 69,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Session\\Bag constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/Bag.zep',
            'line' => 43,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 42,
          'last-line' => 73,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'clear',
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 76,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 78,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 78,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'session',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 78,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 78,
                  'char' => 23,
                ),
                'name' => 'remove',
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
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 78,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 78,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 78,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 78,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 78,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 79,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Destroys the session bag
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/Bag.zep',
            'line' => 75,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 74,
          'last-line' => 83,
          'char' => 19,
        ),
        2 => 
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
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 86,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 86,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 86,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 87,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the DependencyInjector container
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
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 85,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 85,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Bag.zep',
            'line' => 85,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 84,
          'last-line' => 91,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'init',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 92,
                'char' => 42,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 92,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'init',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 94,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 94,
                    'char' => 26,
                  ),
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 94,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes a property from the internal bag
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/Bag.zep',
            'line' => 93,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 92,
          'last-line' => 99,
          'char' => 19,
        ),
        4 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 100,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'remove',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 102,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 102,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 102,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 104,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 104,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'session',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 104,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 104,
                  'char' => 23,
                ),
                'name' => 'set',
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
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 104,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 104,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 104,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 104,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 104,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 104,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 104,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 104,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 104,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 105,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes a property from the internal bag
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/Bag.zep',
            'line' => 101,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 100,
          'last-line' => 109,
          'char' => 19,
        ),
        5 => 
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
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 110,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 110,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'set',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 112,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 112,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 112,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 112,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 112,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 114,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 114,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'session',
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 114,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 114,
                  'char' => 23,
                ),
                'name' => 'set',
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
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 114,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 114,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 114,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 114,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 114,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Session/Bag.zep',
                        'line' => 114,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Session/Bag.zep',
                      'line' => 114,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 114,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 114,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 115,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a value in the session bag
     *',
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 110,
          'last-line' => 119,
          'char' => 19,
        ),
        6 => 
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
                'file' => '/app/phalcon/Session/Bag.zep',
                'line' => 120,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 120,
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
                    'file' => '/app/phalcon/Session/Bag.zep',
                    'line' => 122,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Session/Bag.zep',
                  'line' => 122,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Session/Bag.zep',
              'line' => 123,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the DependencyInjector container
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/Bag.zep',
            'line' => 121,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Bag.zep',
          'line' => 120,
          'last-line' => 124,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Session/Bag.zep',
      'line' => 31,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Session/Bag.zep',
    'line' => 31,
    'char' => 5,
  ),
);