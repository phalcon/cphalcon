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
    'file' => '/app/phalcon/Paginator/Repository.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Paginator',
    'file' => '/app/phalcon/Paginator/Repository.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Paginator/Repository.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Repository.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Paginator\\Repository
 *
 * Repository of current state Phalcon\\Paginator\\AdapterInterface::paginate()
 *',
    'file' => '/app/phalcon/Paginator/Repository.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Repository',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RepositoryInterface',
        'file' => '/app/phalcon/Paginator/Repository.zep',
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
          'name' => 'aliases',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 25,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 29,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'properties',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 30,
            'char' => 30,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 34,
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
              'name' => 'property',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 35,
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
                  'variable' => 'method',
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 37,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 39,
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
                  'variable' => 'method',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'get',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 39,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'camelize',
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
                              'value' => 'this',
                              'file' => '/app/phalcon/Paginator/Repository.zep',
                              'line' => 40,
                              'char' => 18,
                            ),
                            'name' => 'getRealNameProperty',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'property',
                                  'file' => '/app/phalcon/Paginator/Repository.zep',
                                  'line' => 40,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Paginator/Repository.zep',
                                'line' => 40,
                                'char' => 47,
                              ),
                            ),
                            'file' => '/app/phalcon/Paginator/Repository.zep',
                            'line' => 41,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Paginator/Repository.zep',
                          'line' => 41,
                          'char' => 9,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 41,
                      'char' => 10,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 41,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 41,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 43,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'method_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 43,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 43,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'method',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 43,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 43,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 43,
                'char' => 40,
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
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 44,
                      'char' => 25,
                    ),
                    'name' => 'method',
                    'call-type' => 2,
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 44,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 45,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 50,
              'char' => 21,
            ),
            3 => 
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
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'Access to undefined property ',
                            'file' => '/app/phalcon/Paginator/Repository.zep',
                            'line' => 51,
                            'char' => 43,
                          ),
                          'right' => 
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
                                  'file' => '/app/phalcon/Paginator/Repository.zep',
                                  'line' => 51,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Paginator/Repository.zep',
                                'line' => 51,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Paginator/Repository.zep',
                            'line' => 51,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Paginator/Repository.zep',
                          'line' => 51,
                          'char' => 61,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '::',
                          'file' => '/app/phalcon/Paginator/Repository.zep',
                          'line' => 51,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 51,
                        'char' => 66,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'property',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 52,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 52,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 52,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 52,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 54,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 54,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
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
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 35,
                'char' => 51,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 36,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 36,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 35,
          'last-line' => 59,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAliases',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 62,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'aliases',
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 62,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 62,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 63,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
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
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 61,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 61,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 60,
          'last-line' => 67,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCurrent',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 70,
                  'char' => 21,
                ),
                'name' => 'getProperty',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 70,
                        'char' => 61,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'PROPERTY_CURRENT_PAGE',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 70,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 70,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 70,
                    'char' => 61,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 70,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 70,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 70,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 71,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 69,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 69,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 68,
          'last-line' => 75,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFirst',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 78,
                  'char' => 21,
                ),
                'name' => 'getProperty',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 78,
                        'char' => 59,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'PROPERTY_FIRST_PAGE',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 78,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 78,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 78,
                    'char' => 59,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 78,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 78,
                    'char' => 62,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 78,
                'char' => 63,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 79,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 77,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 77,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 76,
          'last-line' => 83,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getItems',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 86,
                  'char' => 21,
                ),
                'name' => 'getProperty',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 86,
                        'char' => 54,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'PROPERTY_ITEMS',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 86,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 86,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 86,
                    'char' => 54,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 86,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 86,
                    'char' => 60,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 86,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 87,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
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
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 85,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 85,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 84,
          'last-line' => 91,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLast',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 94,
                  'char' => 21,
                ),
                'name' => 'getProperty',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 94,
                        'char' => 58,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'PROPERTY_LAST_PAGE',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 94,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 94,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 94,
                    'char' => 58,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 94,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 94,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 94,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 93,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 93,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 92,
          'last-line' => 99,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLimit',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 102,
                  'char' => 21,
                ),
                'name' => 'getProperty',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 102,
                        'char' => 54,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'PROPERTY_LIMIT',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 102,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 102,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 102,
                    'char' => 54,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 102,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 102,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 102,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 101,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 101,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 100,
          'last-line' => 107,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNext',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 110,
                  'char' => 21,
                ),
                'name' => 'getProperty',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 110,
                        'char' => 58,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'PROPERTY_NEXT_PAGE',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 110,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 110,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 110,
                    'char' => 58,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 110,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 110,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 110,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 111,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 108,
          'last-line' => 115,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPrevious',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 118,
                  'char' => 21,
                ),
                'name' => 'getProperty',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 118,
                        'char' => 62,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'PROPERTY_PREVIOUS_PAGE',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 118,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 118,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 118,
                    'char' => 62,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 118,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 118,
                    'char' => 65,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 118,
                'char' => 66,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 119,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 117,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 117,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 116,
          'last-line' => 123,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTotalItems',
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
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 126,
                  'char' => 21,
                ),
                'name' => 'getProperty',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 126,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'PROPERTY_TOTAL_ITEMS',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 126,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 126,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 126,
                    'char' => 60,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 126,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 126,
                    'char' => 63,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 126,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 127,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 125,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 125,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 124,
          'last-line' => 131,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAliases',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'aliases',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 132,
              'char' => 45,
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
                  'property' => 'aliases',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'aliases',
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 134,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 134,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 136,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 136,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 137,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
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
                  'value' => 'RepositoryInterface',
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 133,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 133,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 133,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 132,
          'last-line' => 141,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setProperties',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'properties',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 142,
              'char' => 51,
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
                  'property' => 'properties',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'properties',
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 144,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 144,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 146,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 146,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 147,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * {@inheritdoc}
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
                  'value' => 'RepositoryInterface',
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 143,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 143,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 143,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 142,
          'last-line' => 151,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getProperty',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'property',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 152,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 152,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 152,
              'char' => 76,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Arr',
                'dynamic' => 0,
                'name' => 'get',
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
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 155,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'properties',
                        'file' => '/app/phalcon/Paginator/Repository.zep',
                        'line' => 155,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 155,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 155,
                    'char' => 29,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'property',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 156,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 156,
                    'char' => 21,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 158,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 158,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 158,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 159,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets value of property by name
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
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 153,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 153,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 152,
          'last-line' => 163,
          'char' => 22,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getRealNameProperty',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'property',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 164,
              'char' => 59,
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
                  'variable' => 'aliases',
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 166,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 168,
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
                  'variable' => 'aliases',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 168,
                      'char' => 28,
                    ),
                    'name' => 'getAliases',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 168,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 168,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 170,
              'char' => 10,
            ),
            2 => 
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
                    'type' => 'variable',
                    'value' => 'aliases',
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 170,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'property',
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 170,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 170,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 170,
                'char' => 36,
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
                      'type' => 'variable',
                      'value' => 'aliases',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 171,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'property',
                      'file' => '/app/phalcon/Paginator/Repository.zep',
                      'line' => 171,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Paginator/Repository.zep',
                    'line' => 171,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Paginator/Repository.zep',
                  'line' => 172,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 174,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'property',
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 174,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Paginator/Repository.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resolve alias property name
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
                'file' => '/app/phalcon/Paginator/Repository.zep',
                'line' => 165,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Repository.zep',
            'line' => 165,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Repository.zep',
          'line' => 164,
          'last-line' => 176,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Paginator/Repository.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Paginator/Repository.zep',
    'line' => 20,
    'char' => 5,
  ),
);