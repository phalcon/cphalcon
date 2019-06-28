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
    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Paginator\\Adapter',
    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
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
        'name' => 'Phalcon\\Paginator\\Exception',
        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
        'line' => 13,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
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
        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
        'line' => 14,
        'char' => 46,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
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
        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
        'line' => 15,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
    'line' => 39,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Paginator\\Adapter\\NativeArray
 *
 * Pagination using a PHP array as source of data
 *
 * ```php
 * use Phalcon\\Paginator\\Adapter\\NativeArray;
 *
 * $paginator = new NativeArray(
 *     [
 *         "data"  => [
 *             ["id" => 1, "name" => "Artichoke"],
 *             ["id" => 2, "name" => "Carrots"],
 *             ["id" => 3, "name" => "Beet"],
 *             ["id" => 4, "name" => "Lettuce"],
 *             ["id" => 5, "name" => ""],
 *         ],
 *         "limit" => 2,
 *         "page"  => $currentPage,
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
    'line' => 40,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'NativeArray',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
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
                  'variable' => 'config',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 47,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'items',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 47,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 48,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'show',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 48,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'pageNumber',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 48,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'totalPages',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 48,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'number',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 48,
                  'char' => 49,
                ),
                4 => 
                array (
                  'variable' => 'previous',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 48,
                  'char' => 59,
                ),
                5 => 
                array (
                  'variable' => 'next',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 48,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 49,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'double',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'roundedTotal',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 49,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 54,
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
                  'variable' => 'config',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 54,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 54,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 54,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 54,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'items',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 55,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'data',
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 55,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 55,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 55,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 57,
              'char' => 10,
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
                      'value' => 'items',
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 57,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 57,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 57,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 57,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                'line' => 57,
                'char' => 43,
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
                          'value' => 'Invalid data for paginator',
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 58,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 58,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 58,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 59,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 61,
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
                  'variable' => 'show',
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
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 61,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'limitRows',
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 61,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 61,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 61,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 61,
                  'char' => 47,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'pageNumber',
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
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 62,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'page',
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 62,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 62,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 62,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 62,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 64,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'less-equal',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'pageNumber',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 64,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 64,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                'line' => 64,
                'char' => 27,
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
                      'variable' => 'pageNumber',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 65,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 65,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 66,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 68,
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
                  'variable' => 'number',
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
                          'value' => 'items',
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 68,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 68,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 68,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 68,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'roundedTotal',
                  'expr' => 
                  array (
                    'type' => 'div',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'number',
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 69,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'floatval',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'show',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 69,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 69,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 69,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 69,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 69,
                  'char' => 51,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'totalPages',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'roundedTotal',
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 70,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 70,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 70,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 75,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'totalPages',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 75,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'roundedTotal',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 75,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
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
                      'assign-type' => 'incr',
                      'variable' => 'totalPages',
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 76,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 77,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 79,
              'char' => 11,
            ),
            9 => 
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
                    'type' => 'fcall',
                    'name' => 'array_slice',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'items',
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 80,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 80,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'mul',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'show',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 81,
                            'char' => 18,
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
                                'value' => 'pageNumber',
                                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                                'line' => 81,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                                'line' => 81,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 81,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 81,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 81,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 81,
                        'char' => 36,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'show',
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 83,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 83,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 83,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 83,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 86,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'less',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'pageNumber',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 86,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'totalPages',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 86,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                'line' => 86,
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
                          'value' => 'pageNumber',
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 87,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 87,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 87,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 87,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 88,
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
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 89,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 89,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 90,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 92,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'pageNumber',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 92,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 92,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                'line' => 92,
                'char' => 27,
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
                        'type' => 'sub',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pageNumber',
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 93,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 93,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 93,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 93,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 94,
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
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                        'line' => 95,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 95,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 96,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 98,
              'char' => 14,
            ),
            12 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 98,
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
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 100,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_ITEMS',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 100,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 100,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'items',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 100,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 100,
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
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 101,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_TOTAL_ITEMS',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 101,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 101,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'number',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 101,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 101,
                          'char' => 69,
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
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 102,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_LIMIT',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 102,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 102,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 102,
                              'char' => 68,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'limitRows',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 102,
                              'char' => 78,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 102,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 102,
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
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 103,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_FIRST_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 103,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 103,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 103,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 103,
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
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 104,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_PREVIOUS_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 104,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 104,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'previous',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 104,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 104,
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
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 105,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_CURRENT_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 105,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 105,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'pageNumber',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 105,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 105,
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
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 106,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_NEXT_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 106,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 106,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'next',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 106,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 106,
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
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 107,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_LAST_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                              'line' => 107,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 107,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'totalPages',
                            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                            'line' => 108,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                          'line' => 108,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                      'line' => 109,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                    'line' => 109,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                'line' => 109,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
              'line' => 110,
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
                  'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                  'line' => 46,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
                'line' => 46,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
            'line' => 46,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
          'line' => 45,
          'last-line' => 111,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
      'line' => 40,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Paginator/Adapter/NativeArray.zep',
    'line' => 40,
    'char' => 5,
  ),
);