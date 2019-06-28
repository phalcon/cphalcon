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
    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Paginator\\Adapter',
    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Paginator\\Repository',
        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
        'line' => 13,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Paginator\\RepositoryInterface',
        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
        'line' => 14,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Paginator\\Adapter\\AbstractAdapter
 *',
    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
    'line' => 19,
    'char' => 8,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'AbstractAdapter',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'AdapterInterface',
        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
        'line' => 20,
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
          'name' => 'config',
          'docblock' => '**
     * Configuration of paginator
     *',
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 28,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'limitRows',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
            'line' => 29,
            'char' => 31,
          ),
          'docblock' => '**
     * Number of rows to show in the paginator. By default is null
     *',
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 33,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'page',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
            'line' => 34,
            'char' => 26,
          ),
          'docblock' => '**
     * Current page in paginate
     *',
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 40,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'repository',
          'docblock' => '**
     * Repository for pagination
     *
     * @var RepositoryInterface
     *',
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 45,
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
              'name' => 'config',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 46,
              'char' => 46,
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
                  'property' => 'config',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'config',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 48,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 48,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 50,
              'char' => 10,
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
                    'type' => 'variable',
                    'value' => 'config',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 50,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'limit',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 50,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 50,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 50,
                'char' => 32,
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
                      'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                      'line' => 51,
                      'char' => 18,
                    ),
                    'name' => 'setLimit',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'config',
                            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                            'line' => 52,
                            'char' => 23,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'limit',
                            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                            'line' => 52,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                          'line' => 53,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                        'line' => 53,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 53,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 54,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 56,
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
                    'value' => 'config',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 56,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'page',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 56,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 56,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 56,
                'char' => 31,
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
                      'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                      'line' => 57,
                      'char' => 18,
                    ),
                    'name' => 'setCurrentPage',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'config',
                            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                            'line' => 58,
                            'char' => 23,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'page',
                            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                            'line' => 58,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                          'line' => 59,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                        'line' => 59,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 59,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 60,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 62,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'config',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 62,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'repository',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 62,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 62,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 62,
                'char' => 37,
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
                      'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                      'line' => 63,
                      'char' => 18,
                    ),
                    'name' => 'setRepository',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'config',
                            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                            'line' => 64,
                            'char' => 23,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'repository',
                            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                            'line' => 64,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                          'line' => 65,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                        'line' => 65,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 65,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 66,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 67,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Paginator\\Adapter\\AbstractAdapter constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
            'line' => 47,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 46,
          'last-line' => 71,
          'char' => 19,
        ),
        1 => 
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
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 74,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'limitRows',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 74,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 74,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 75,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get current rows limit
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
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 73,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
            'line' => 73,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 72,
          'last-line' => 79,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setCurrentPage',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'page',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 80,
              'char' => 44,
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
                  'property' => 'page',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'page',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 82,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 82,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 84,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 84,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 85,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the current page number
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
                  'value' => 'Adapter',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 81,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 81,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
            'line' => 81,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 80,
          'last-line' => 89,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setLimit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'limitRows',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 90,
              'char' => 43,
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
                  'property' => 'limitRows',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'limitRows',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 92,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 92,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 94,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 94,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set current rows limit
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
                  'value' => 'Adapter',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 91,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 91,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
            'line' => 91,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 90,
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
          'name' => 'setRepository',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'repository',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'RepositoryInterface',
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 100,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 100,
              'char' => 67,
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
                  'property' => 'repository',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'repository',
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 102,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 102,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 104,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 104,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 105,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets current repository for pagination
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
                  'value' => 'Adapter',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 101,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 101,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
            'line' => 101,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 100,
          'last-line' => 109,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getRepository',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'properties',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 110,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 110,
              'char' => 61,
            ),
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                      'line' => 112,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'repository',
                      'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                      'line' => 112,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 112,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 112,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 112,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 112,
                'char' => 46,
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
                      'property' => 'repository',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Repository',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                        'line' => 113,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                      'line' => 113,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 114,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 116,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'properties',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 116,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 116,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 116,
                'char' => 32,
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                        'line' => 117,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'repository',
                        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                        'line' => 117,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                      'line' => 117,
                      'char' => 30,
                    ),
                    'name' => 'setProperties',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'properties',
                          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                          'line' => 117,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                        'line' => 117,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                    'line' => 117,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 118,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 120,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 120,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'repository',
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 120,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 120,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
              'line' => 121,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets current repository for pagination
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
                  'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                  'line' => 111,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
          'line' => 110,
          'last-line' => 122,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
      'line' => 19,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Paginator/Adapter/AbstractAdapter.zep',
    'line' => 19,
    'char' => 14,
  ),
);