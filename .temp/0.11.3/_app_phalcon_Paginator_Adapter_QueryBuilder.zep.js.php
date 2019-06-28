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
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Paginator\\Adapter',
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Query\\Builder',
        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
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
        'name' => 'Phalcon\\Paginator\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
        'line' => 14,
        'char' => 46,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
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
        'name' => 'Phalcon\\Paginator\\RepositoryInterface',
        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
        'line' => 15,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
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
        'name' => 'Phalcon\\Paginator\\Exception',
        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
        'line' => 16,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
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
        'name' => 'Phalcon\\Db',
        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
        'line' => 17,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
    'line' => 40,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Paginator\\Adapter\\QueryBuilder
 *
 * Pagination using a PHQL query builder as source of data
 *
 * ```php
 * use Phalcon\\Paginator\\Adapter\\QueryBuilder;
 *
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("id, name")
 *                 ->from(Robots::class)
 *                 ->orderBy("name");
 *
 * $paginator = new QueryBuilder(
 *     [
 *         "builder" => $builder,
 *         "limit"   => 20,
 *         "page"    => 1,
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
    'line' => 41,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'QueryBuilder',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
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
          'name' => 'builder',
          'docblock' => '**
     * Paginator\'s data
     *',
          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
          'line' => 50,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'columns',
          'docblock' => '**
     * Columns for count query if builder has having
     *',
          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
          'line' => 55,
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 56,
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
                  'variable' => 'builder',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 58,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 58,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 60,
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
                        'type' => 'variable',
                        'value' => 'config',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 60,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'limit',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 60,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 60,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 60,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 60,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 60,
                'char' => 42,
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
                          'value' => 'Parameter \'limit\' is required',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 61,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 61,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 61,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 62,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 64,
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'builder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 64,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'config',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 64,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'builder',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 64,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 64,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 64,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 64,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 64,
                'char' => 53,
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
                          'value' => 'Parameter \'builder\' is required',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 65,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 65,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 65,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 66,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 68,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'columns',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 68,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'config',
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 68,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'columns',
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 68,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 68,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 68,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'columns',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 69,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 69,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 70,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 72,
              'char' => 14,
            ),
            4 => 
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
                      'value' => 'config',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 72,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 72,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 72,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 74,
              'char' => 12,
            ),
            5 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 74,
                  'char' => 14,
                ),
                'name' => 'setQueryBuilder',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'builder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 74,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 74,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 74,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 75,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Paginator\\Adapter\\QueryBuilder
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
            'line' => 57,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
          'line' => 56,
          'last-line' => 78,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCurrentPage',
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
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 81,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'page',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 81,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 81,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 82,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the current page number
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
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 80,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
            'line' => 80,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
          'line' => 79,
          'last-line' => 86,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getQueryBuilder',
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
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 89,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'builder',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 89,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 89,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 90,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get query builder object
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
                  'value' => 'Builder',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 88,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 88,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
            'line' => 88,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
          'line' => 87,
          'last-line' => 94,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'paginate',
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
                  'variable' => 'originalBuilder',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 97,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'builder',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 97,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'totalBuilder',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 97,
                  'char' => 51,
                ),
                3 => 
                array (
                  'variable' => 'totalPages',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 97,
                  'char' => 63,
                ),
                4 => 
                array (
                  'variable' => 'limit',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 97,
                  'char' => 70,
                ),
                5 => 
                array (
                  'variable' => 'number',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 98,
                  'char' => 19,
                ),
                6 => 
                array (
                  'variable' => 'query',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 98,
                  'char' => 26,
                ),
                7 => 
                array (
                  'variable' => 'previous',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 98,
                  'char' => 36,
                ),
                8 => 
                array (
                  'variable' => 'items',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 98,
                  'char' => 43,
                ),
                9 => 
                array (
                  'variable' => 'totalQuery',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 98,
                  'char' => 55,
                ),
                10 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 98,
                  'char' => 63,
                ),
                11 => 
                array (
                  'variable' => 'row',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 98,
                  'char' => 68,
                ),
                12 => 
                array (
                  'variable' => 'rowcount',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 98,
                  'char' => 78,
                ),
                13 => 
                array (
                  'variable' => 'next',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 99,
                  'char' => 17,
                ),
                14 => 
                array (
                  'variable' => 'sql',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 99,
                  'char' => 22,
                ),
                15 => 
                array (
                  'variable' => 'columns',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 99,
                  'char' => 31,
                ),
                16 => 
                array (
                  'variable' => 'db',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 99,
                  'char' => 35,
                ),
                17 => 
                array (
                  'variable' => 'model',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 99,
                  'char' => 42,
                ),
                18 => 
                array (
                  'variable' => 'modelClass',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 99,
                  'char' => 54,
                ),
                19 => 
                array (
                  'variable' => 'dbService',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 99,
                  'char' => 65,
                ),
                20 => 
                array (
                  'variable' => 'groups',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 99,
                  'char' => 73,
                ),
                21 => 
                array (
                  'variable' => 'groupColumn',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 100,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 101,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'hasHaving',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 101,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'hasGroup',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 101,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 102,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'numberPage',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 102,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 104,
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
                  'variable' => 'originalBuilder',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 104,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'builder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 104,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 104,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 104,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 105,
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
                  'variable' => 'columns',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 105,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columns',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 105,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 105,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 105,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 110,
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
                  'variable' => 'builder',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'originalBuilder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 110,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 110,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 110,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 115,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'totalBuilder',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'builder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 115,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 115,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 115,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 117,
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
                  'variable' => 'limit',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 117,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'limitRows',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 117,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 117,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 117,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 118,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'numberPage',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 118,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'page',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 118,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 118,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 118,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 118,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 120,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'numberPage',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 120,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 120,
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
                      'variable' => 'numberPage',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 121,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 121,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 122,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 124,
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
                  'variable' => 'number',
                  'expr' => 
                  array (
                    'type' => 'mul',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'limit',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 124,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'sub',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'numberPage',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 124,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 124,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 124,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 124,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 124,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 124,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 129,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'less',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'number',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 129,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'limit',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 129,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 129,
                'char' => 27,
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
                      'value' => 'builder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 130,
                      'char' => 21,
                    ),
                    'name' => 'limit',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'limit',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 130,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 130,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 130,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 131,
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
                      'value' => 'builder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 132,
                      'char' => 21,
                    ),
                    'name' => 'limit',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'limit',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 132,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 132,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'number',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 132,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 132,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 132,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 133,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 135,
              'char' => 11,
            ),
            12 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'query',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'builder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 135,
                      'char' => 29,
                    ),
                    'name' => 'getQuery',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 135,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 135,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 137,
              'char' => 10,
            ),
            13 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'numberPage',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 137,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 137,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 137,
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
                      'variable' => 'previous',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 138,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 138,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 139,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'previous',
                      'expr' => 
                      array (
                        'type' => 'sub',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'numberPage',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 140,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 140,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 140,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 140,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 141,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 146,
              'char' => 11,
            ),
            14 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'items',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'query',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 146,
                      'char' => 27,
                    ),
                    'name' => 'execute',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 146,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 146,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 148,
              'char' => 11,
            ),
            15 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'hasHaving',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'totalBuilder',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 148,
                          'char' => 45,
                        ),
                        'name' => 'getHaving',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 148,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 148,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 148,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 148,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 150,
              'char' => 11,
            ),
            16 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'groups',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'totalBuilder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 150,
                      'char' => 35,
                    ),
                    'name' => 'getGroupBy',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 150,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 150,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 152,
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
                  'variable' => 'hasGroup',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'groups',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 152,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 152,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 152,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 152,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 158,
              'char' => 10,
            ),
            18 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'hasHaving',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 158,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'hasGroup',
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 158,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 158,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 158,
                'char' => 35,
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
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columns',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 159,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 159,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 159,
                    'char' => 39,
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
                              'value' => 'When having is set there should be columns option provided for which calculate row count',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 162,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 162,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 162,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 163,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 165,
                  'char' => 24,
                ),
                1 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'totalBuilder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 165,
                      'char' => 26,
                    ),
                    'name' => 'columns',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columns',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 165,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 165,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 165,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 166,
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
                      'value' => 'totalBuilder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 167,
                      'char' => 26,
                    ),
                    'name' => 'columns',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'COUNT(*) [rowcount]',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 167,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 167,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 167,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 168,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 173,
              'char' => 10,
            ),
            19 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'hasGroup',
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 173,
                'char' => 21,
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
                        'value' => 'groups',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 174,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 174,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 174,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 174,
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
                          'variable' => 'groupColumn',
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
                                  'type' => 'string',
                                  'value' => ', ',
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 175,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 175,
                                'char' => 45,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'groups',
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 175,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 175,
                                'char' => 53,
                              ),
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 175,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 175,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 176,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'groupColumn',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'groups',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 177,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 177,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 178,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 180,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hasHaving',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 180,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 180,
                    'char' => 27,
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'totalBuilder',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 181,
                            'char' => 30,
                          ),
                          'name' => 'groupBy',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'null',
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 181,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 181,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 181,
                          'char' => 45,
                        ),
                        'name' => 'columns',
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
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'COUNT(DISTINCT ',
                                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                        'line' => 183,
                                        'char' => 41,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'groupColumn',
                                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                        'line' => 183,
                                        'char' => 55,
                                      ),
                                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                      'line' => 183,
                                      'char' => 55,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ') AS [rowcount]',
                                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                      'line' => 184,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                    'line' => 184,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 184,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 185,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 185,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 185,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 186,
                      'char' => 13,
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
                          'value' => 'totalBuilder',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 187,
                          'char' => 30,
                        ),
                        'name' => 'columns',
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
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'DISTINCT ',
                                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                      'line' => 189,
                                      'char' => 35,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'groupColumn',
                                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                      'line' => 190,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                    'line' => 190,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 190,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 191,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 191,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 191,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 192,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 193,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 198,
              'char' => 20,
            ),
            20 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'totalBuilder',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 198,
                  'char' => 22,
                ),
                'name' => 'orderBy',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 198,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 198,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 198,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 203,
              'char' => 11,
            ),
            21 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'totalQuery',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'totalBuilder',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 203,
                      'char' => 39,
                    ),
                    'name' => 'getQuery',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 203,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 203,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 209,
              'char' => 10,
            ),
            22 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'hasHaving',
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 209,
                'char' => 22,
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
                      'variable' => 'sql',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'totalQuery',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 210,
                          'char' => 34,
                        ),
                        'name' => 'getSql',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 210,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 210,
                      'char' => 43,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'modelClass',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'builder',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 211,
                          'char' => 38,
                        ),
                        'name' => 'getModels',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 211,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 211,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 213,
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
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'modelClass',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 213,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 213,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 213,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 213,
                    'char' => 45,
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
                              'value' => 'Model not defined in builder',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 214,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 214,
                            'char' => 65,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 214,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 215,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 217,
                  'char' => 14,
                ),
                2 => 
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
                        'value' => 'modelClass',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 217,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 217,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 217,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 217,
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
                          'variable' => 'modelClass',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'array_values',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'modelClass',
                                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                    'line' => 218,
                                    'char' => 57,
                                  ),
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 218,
                                  'char' => 57,
                                ),
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 218,
                              'char' => 58,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 218,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 218,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 218,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 219,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 221,
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
                      'variable' => 'model',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'modelClass',
                        'dynamic' => 1,
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 221,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 221,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 222,
                  'char' => 15,
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
                      'variable' => 'dbService',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'model',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 222,
                          'char' => 35,
                        ),
                        'name' => 'getReadConnectionService',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 222,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 222,
                      'char' => 62,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 223,
                  'char' => 15,
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
                      'variable' => 'db',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'totalBuilder',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 223,
                            'char' => 35,
                          ),
                          'name' => 'getDI',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 223,
                          'char' => 44,
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
                              'value' => 'dbService',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 223,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 223,
                            'char' => 58,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 223,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 223,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 225,
                  'char' => 15,
                ),
                6 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'row',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'db',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 225,
                          'char' => 26,
                        ),
                        'name' => 'fetchOne',
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
                                  'type' => 'string',
                                  'value' => 'SELECT COUNT(*) as \\"rowcount\\" FROM (',
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 226,
                                  'char' => 56,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'sql',
                                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                    'line' => 226,
                                    'char' => 62,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'sql',
                                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                    'line' => 226,
                                    'char' => 66,
                                  ),
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 226,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 226,
                                'char' => 68,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ') as T1',
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 226,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 226,
                              'char' => 77,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 226,
                            'char' => 77,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'static-constant-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'Db',
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 227,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'FETCH_ASSOC',
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 227,
                                'char' => 32,
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 227,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 227,
                            'char' => 32,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'sql',
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 228,
                                'char' => 20,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'bind',
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 228,
                                'char' => 25,
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 229,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 229,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 229,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 229,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 231,
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
                      'variable' => 'rowcount',
                      'expr' => 
                      array (
                        'type' => 'ternary',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'row',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 231,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'intval',
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
                                  'value' => 'row',
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 231,
                                  'char' => 44,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'rowcount',
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 231,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 231,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 231,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 231,
                          'char' => 56,
                        ),
                        'extra' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 231,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 231,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 231,
                      'char' => 59,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'totalPages',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'intval',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'ceil',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'div',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'rowcount',
                                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                      'line' => 232,
                                      'char' => 51,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'limit',
                                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                      'line' => 232,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                    'line' => 232,
                                    'char' => 58,
                                  ),
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 232,
                                  'char' => 58,
                                ),
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 232,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 232,
                            'char' => 59,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 232,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 232,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 233,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'totalQuery',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 234,
                          'char' => 37,
                        ),
                        'name' => 'execute',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 234,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 234,
                      'char' => 47,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'row',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'result',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 235,
                          'char' => 30,
                        ),
                        'name' => 'getFirst',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 235,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 235,
                      'char' => 41,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'rowcount',
                      'expr' => 
                      array (
                        'type' => 'ternary',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'row',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 236,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'intval',
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
                                  'value' => 'row',
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 236,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'rowcount',
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 236,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                'line' => 236,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 236,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 236,
                          'char' => 56,
                        ),
                        'extra' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 236,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 236,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 236,
                      'char' => 59,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'totalPages',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'intval',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'ceil',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'div',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'rowcount',
                                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                      'line' => 237,
                                      'char' => 51,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'limit',
                                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                      'line' => 237,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                    'line' => 237,
                                    'char' => 58,
                                  ),
                                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                                  'line' => 237,
                                  'char' => 58,
                                ),
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 237,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 237,
                            'char' => 59,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 237,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 237,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 238,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 240,
              'char' => 10,
            ),
            23 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'less',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'numberPage',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 240,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'totalPages',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 240,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 240,
                'char' => 36,
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
                      'variable' => 'next',
                      'expr' => 
                      array (
                        'type' => 'add',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'numberPage',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 241,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 241,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 241,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 241,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 242,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'next',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'totalPages',
                        'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                        'line' => 243,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 243,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 244,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 246,
              'char' => 14,
            ),
            24 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 246,
                  'char' => 21,
                ),
                'name' => 'getRepository',
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
                          'key' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RepositoryInterface',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 248,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_ITEMS',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 248,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 248,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'items',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 248,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 248,
                          'char' => 68,
                        ),
                        1 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RepositoryInterface',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 249,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_TOTAL_ITEMS',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 249,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 249,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'rowcount',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 249,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 249,
                          'char' => 71,
                        ),
                        2 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RepositoryInterface',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 250,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_LIMIT',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 250,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 250,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 250,
                              'char' => 68,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'limitRows',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 250,
                              'char' => 78,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 250,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 250,
                          'char' => 78,
                        ),
                        3 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RepositoryInterface',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 251,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_FIRST_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 251,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 251,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 251,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 251,
                          'char' => 64,
                        ),
                        4 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RepositoryInterface',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 252,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_PREVIOUS_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 252,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 252,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'previous',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 252,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 252,
                          'char' => 71,
                        ),
                        5 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RepositoryInterface',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 253,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_CURRENT_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 253,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 253,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'numberPage',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 253,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 253,
                          'char' => 73,
                        ),
                        6 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RepositoryInterface',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 254,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_NEXT_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 254,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 254,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'next',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 254,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 254,
                          'char' => 67,
                        ),
                        7 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'static-constant-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RepositoryInterface',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 255,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_LAST_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                              'line' => 255,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 255,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'totalPages',
                            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                            'line' => 256,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                          'line' => 256,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                      'line' => 257,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 257,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 257,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 258,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a slice of the resultset to show in the pagination
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
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 96,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 96,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
            'line' => 96,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
          'line' => 95,
          'last-line' => 262,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setQueryBuilder',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'builder',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Builder',
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 263,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 263,
              'char' => 54,
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
                  'property' => 'builder',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'builder',
                    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                    'line' => 265,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 265,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 267,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 267,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
              'line' => 268,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set query builder object
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
                  'value' => 'QueryBuilder',
                  'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                  'line' => 264,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
                'line' => 264,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
            'line' => 264,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
          'line' => 263,
          'last-line' => 269,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
      'line' => 41,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Paginator/Adapter/QueryBuilder.zep',
    'line' => 41,
    'char' => 5,
  ),
);