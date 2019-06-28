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
    'file' => '/app/phalcon/Filter/Filter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter',
    'file' => '/app/phalcon/Filter/Filter.zep',
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
        'file' => '/app/phalcon/Filter/Filter.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Filter/Filter.zep',
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
        'name' => 'Phalcon\\Filter\\Exception',
        'file' => '/app/phalcon/Filter/Filter.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Filter/Filter.zep',
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
        'name' => 'Phalcon\\Filter\\FilterInterface',
        'file' => '/app/phalcon/Filter/Filter.zep',
        'line' => 15,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Filter/Filter.zep',
    'line' => 19,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Lazy loads, stores and exposes sanitizer objects
 *',
    'file' => '/app/phalcon/Filter/Filter.zep',
    'line' => 20,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Filter',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'FilterInterface',
        'file' => '/app/phalcon/Filter/Filter.zep',
        'line' => 21,
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
          'name' => 'mapper',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 47,
            'char' => 26,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 51,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'services',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 52,
            'char' => 28,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 57,
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
              'name' => 'mapper',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 58,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 58,
              'char' => 51,
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
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 60,
                  'char' => 14,
                ),
                'name' => 'init',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mapper',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 60,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 60,
                    'char' => 26,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 60,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Key value pairs with name as the key and a callable as the value for
     * the service object
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 59,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 58,
          'last-line' => 66,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 67,
              'char' => 37,
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
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 69,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 71,
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
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 71,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mapper',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 71,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 71,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 71,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 71,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 71,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 71,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 71,
                'char' => 47,
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
                              'value' => 'The service ',
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 73,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 73,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 73,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' has not been found in the locator',
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 74,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 74,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 74,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 74,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 75,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 77,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'list',
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
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 77,
                          'char' => 24,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'services',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 77,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 77,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 77,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 77,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 77,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 77,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 77,
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
                      'variable' => 'definition',
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
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 78,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 78,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 78,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 78,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 78,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 78,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 79,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 79,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 79,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 79,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 79,
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
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 80,
                              'char' => 40,
                            ),
                          ),
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
                                  'value' => 'definition',
                                  'file' => '/app/phalcon/Filter/Filter.zep',
                                  'line' => 80,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 80,
                                'char' => 70,
                              ),
                            ),
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 80,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 80,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 81,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
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
                          'value' => 'definition',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 81,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Closure',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 81,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 81,
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
                                  'file' => '/app/phalcon/Filter/Filter.zep',
                                  'line' => 82,
                                  'char' => 40,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'call_user_func',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'definition',
                                      'file' => '/app/phalcon/Filter/Filter.zep',
                                      'line' => 82,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Filter/Filter.zep',
                                    'line' => 82,
                                    'char' => 69,
                                  ),
                                ),
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 82,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 82,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 83,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 83,
                      'char' => 18,
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
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 84,
                              'char' => 40,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'definition',
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 84,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 84,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 85,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 86,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 88,
              'char' => 14,
            ),
            3 => 
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
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 88,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 88,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 88,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 88,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 88,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 89,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get a service. If it is not in the mapper array, create a new object,
     * set it and then return it.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 68,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 68,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 67,
          'last-line' => 93,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 94,
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
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 96,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mapper',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 96,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 96,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 96,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 96,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 96,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 97,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a service exists in the map array
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
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 95,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 95,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 94,
          'last-line' => 101,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'sanitize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 102,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'sanitizers',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 102,
              'char' => 55,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'noRecursive',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 102,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 102,
              'char' => 81,
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
                  'variable' => 'sanitizer',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 104,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'sanitizerKey',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 104,
                  'char' => 36,
                ),
                2 => 
                array (
                  'variable' => 'sanitizerName',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 104,
                  'char' => 51,
                ),
                3 => 
                array (
                  'variable' => 'sanitizerParams',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 104,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 138,
              'char' => 10,
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
                    'value' => 'sanitizers',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 138,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 138,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 138,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 138,
                'char' => 39,
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
                      'type' => 'null',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 142,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 142,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 142,
                    'char' => 31,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 143,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 144,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 149,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sanitizers',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 149,
                    'char' => 55,
                  ),
                  'key' => 'sanitizerKey',
                  'value' => 'sanitizer',
                  'reverse' => 0,
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
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'sanitizer',
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 154,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 154,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 154,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 154,
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
                              'variable' => 'sanitizerName',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'sanitizerKey',
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 155,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 155,
                              'char' => 56,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'sanitizerParams',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'sanitizer',
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 156,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 156,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 157,
                          'char' => 18,
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
                              'variable' => 'sanitizerName',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'sanitizer',
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 158,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 158,
                              'char' => 53,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'sanitizerParams',
                              'expr' => 
                              array (
                                'type' => 'empty-array',
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 159,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 159,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 160,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 167,
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
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 167,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 167,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 167,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 167,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'noRecursive',
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 167,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 167,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 167,
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
                              'variable' => 'value',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Filter/Filter.zep',
                                  'line' => 168,
                                  'char' => 38,
                                ),
                                'name' => 'processArrayValues',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'value',
                                      'file' => '/app/phalcon/Filter/Filter.zep',
                                      'line' => 169,
                                      'char' => 30,
                                    ),
                                    'file' => '/app/phalcon/Filter/Filter.zep',
                                    'line' => 169,
                                    'char' => 30,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'sanitizerName',
                                      'file' => '/app/phalcon/Filter/Filter.zep',
                                      'line' => 170,
                                      'char' => 38,
                                    ),
                                    'file' => '/app/phalcon/Filter/Filter.zep',
                                    'line' => 170,
                                    'char' => 38,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'sanitizerParams',
                                      'file' => '/app/phalcon/Filter/Filter.zep',
                                      'line' => 172,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Filter/Filter.zep',
                                    'line' => 172,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 172,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 172,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 173,
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
                              'variable' => 'value',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Filter/Filter.zep',
                                  'line' => 174,
                                  'char' => 38,
                                ),
                                'name' => 'sanitizer',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'value',
                                      'file' => '/app/phalcon/Filter/Filter.zep',
                                      'line' => 175,
                                      'char' => 30,
                                    ),
                                    'file' => '/app/phalcon/Filter/Filter.zep',
                                    'line' => 175,
                                    'char' => 30,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'sanitizerName',
                                      'file' => '/app/phalcon/Filter/Filter.zep',
                                      'line' => 176,
                                      'char' => 38,
                                    ),
                                    'file' => '/app/phalcon/Filter/Filter.zep',
                                    'line' => 176,
                                    'char' => 38,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'sanitizerParams',
                                      'file' => '/app/phalcon/Filter/Filter.zep',
                                      'line' => 178,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Filter/Filter.zep',
                                    'line' => 178,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 178,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 178,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 179,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 180,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 182,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 182,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 183,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 189,
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
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 189,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 189,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 189,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 189,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'noRecursive',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 189,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 189,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 189,
                'char' => 50,
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
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 190,
                      'char' => 25,
                    ),
                    'name' => 'processArrayValues',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 190,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 190,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sanitizers',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 190,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 190,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 190,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 191,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 196,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 196,
                  'char' => 21,
                ),
                'name' => 'sanitizer',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 196,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 196,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sanitizers',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 196,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 196,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 196,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 197,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sanitizes a value with a specified single or set of sanitizers
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
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 103,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 103,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 102,
          'last-line' => 201,
          'char' => 19,
        ),
        4 => 
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
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 202,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'service',
              'const' => 0,
              'data-type' => 'callable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 202,
              'char' => 55,
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
                  'property' => 'mapper',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 204,
                      'char' => 30,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'service',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 204,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 204,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 206,
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
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 206,
                    'char' => 20,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 206,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 206,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 206,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 206,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 207,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set a new service to the mapper array
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 203,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 202,
          'last-line' => 211,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'init',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'mapper',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 212,
              'char' => 42,
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
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 214,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'service',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 214,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 216,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'mapper',
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 216,
                'char' => 37,
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
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 217,
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
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 217,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 217,
                        'char' => 27,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'service',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 217,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 217,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 217,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 218,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 219,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Loads the objects in the internal mapper array
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 213,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 212,
          'last-line' => 223,
          'char' => 22,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'processArrayValues',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 225,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'sanitizerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 226,
              'char' => 29,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'sanitizerParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 228,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 228,
              'char' => 5,
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
                  'variable' => 'itemKey',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 230,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'itemValue',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 230,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 231,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'arrayValue',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 231,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 233,
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
                  'variable' => 'arrayValue',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 233,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 233,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 235,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'values',
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 235,
                'char' => 42,
              ),
              'key' => 'itemKey',
              'value' => 'itemValue',
              'reverse' => 0,
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
                      'variable' => 'arrayValue',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'itemKey',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 236,
                          'char' => 35,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 236,
                          'char' => 44,
                        ),
                        'name' => 'sanitizer',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'itemValue',
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 237,
                              'char' => 26,
                            ),
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 237,
                            'char' => 26,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sanitizerName',
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 238,
                              'char' => 30,
                            ),
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 238,
                            'char' => 30,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sanitizerParams',
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 240,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Filter/Filter.zep',
                            'line' => 240,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 240,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 240,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 241,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 243,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'arrayValue',
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 243,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 244,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Processes the array values with the relevant sanitizers
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
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 229,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 229,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 224,
          'last-line' => 248,
          'char' => 20,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'sanitizer',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 250,
              'char' => 18,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'sanitizerName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 251,
              'char' => 30,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'sanitizerParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 253,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 253,
              'char' => 5,
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
                  'variable' => 'sanitizerObject',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 255,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 255,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 257,
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 257,
                    'char' => 18,
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
                        'value' => 'sanitizerName',
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 257,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 257,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 257,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 257,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 258,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 259,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 261,
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
                  'variable' => 'sanitizerObject',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 261,
                      'char' => 36,
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
                          'value' => 'sanitizerName',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 261,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 261,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 261,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 261,
                  'char' => 55,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'params',
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
                          'type' => 'array',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'value' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Filter/Filter.zep',
                                'line' => 262,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Filter/Filter.zep',
                              'line' => 262,
                              'char' => 49,
                            ),
                          ),
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 262,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 262,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sanitizerParams',
                          'file' => '/app/phalcon/Filter/Filter.zep',
                          'line' => 262,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Filter/Filter.zep',
                        'line' => 262,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 262,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Filter/Filter.zep',
                  'line' => 262,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 264,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
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
                      'value' => 'sanitizerObject',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 264,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 264,
                    'char' => 52,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Filter/Filter.zep',
                      'line' => 264,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Filter/Filter.zep',
                    'line' => 264,
                    'char' => 60,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 264,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Filter/Filter.zep',
              'line' => 265,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Internal sanitize wrapper for recursion
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
                'file' => '/app/phalcon/Filter/Filter.zep',
                'line' => 254,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 254,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 249,
          'last-line' => 266,
          'char' => 20,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_ABSINT',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'absint',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 22,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 23,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_ALNUM',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'alnum',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 23,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 24,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_ALPHA',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'alpha',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 24,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 25,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_BOOL',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'bool',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 25,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 26,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_EMAIL',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'email',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 26,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 27,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_FLOAT',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'float',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 27,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 28,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_INT',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'int',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 28,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 29,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_LOWER',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'lower',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 29,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 30,
          'char' => 9,
        ),
        8 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_LOWERFIRST',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'lowerFirst',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 30,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 31,
          'char' => 9,
        ),
        9 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_REGEX',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'regex',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 31,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 32,
          'char' => 9,
        ),
        10 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_REMOVE',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'remove',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 32,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 33,
          'char' => 9,
        ),
        11 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_REPLACE',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'replace',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 33,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 34,
          'char' => 9,
        ),
        12 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_SPECIAL',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'special',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 34,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 35,
          'char' => 9,
        ),
        13 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_SPECIALFULL',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'specialFull',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 35,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 36,
          'char' => 9,
        ),
        14 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_STRING',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'string',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 36,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 37,
          'char' => 9,
        ),
        15 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_STRIPTAGS',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'striptags',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 37,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 38,
          'char' => 9,
        ),
        16 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_TRIM',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'trim',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 38,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 39,
          'char' => 9,
        ),
        17 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_UPPER',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'upper',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 39,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 40,
          'char' => 9,
        ),
        18 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_UPPERFIRST',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'upperFirst',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 40,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 41,
          'char' => 9,
        ),
        19 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_UPPERWORDS',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'upperWords',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 41,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 42,
          'char' => 9,
        ),
        20 => 
        array (
          'type' => 'const',
          'name' => 'FILTER_URL',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'url',
            'file' => '/app/phalcon/Filter/Filter.zep',
            'line' => 42,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Filter/Filter.zep',
          'line' => 46,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Filter/Filter.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Filter.zep',
    'line' => 20,
    'char' => 5,
  ),
);