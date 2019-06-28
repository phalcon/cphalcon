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
    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Paginator\\Adapter',
    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
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
        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
        'line' => 13,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
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
        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
        'line' => 14,
        'char' => 46,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
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
        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
        'line' => 15,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
    'line' => 36,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Paginator\\Adapter\\Model
 *
 * This adapter allows to paginate data using a Phalcon\\Mvc\\Model resultset as a
 * base.
 *
 * ```php
 * use Phalcon\\Paginator\\Adapter\\Model;
 *
 * $paginator = new Model(
 *     [
 *         "data"  => Robots::find(),
 *         "limit" => 25,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 * $paginate = $paginator->paginate();
 *```
 *',
    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
    'line' => 37,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Model',
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
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 44,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'items',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 44,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'pageItems',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 44,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 45,
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
                  'variable' => 'pageNumber',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 45,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'show',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 45,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'n',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 45,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'start',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 45,
                  'char' => 39,
                ),
                4 => 
                array (
                  'variable' => 'lastShowPage',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 45,
                  'char' => 53,
                ),
                5 => 
                array (
                  'variable' => 'i',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 45,
                  'char' => 56,
                ),
                6 => 
                array (
                  'variable' => 'next',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 45,
                  'char' => 62,
                ),
                7 => 
                array (
                  'variable' => 'totalPages',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 45,
                  'char' => 74,
                ),
                8 => 
                array (
                  'variable' => 'previous',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 46,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
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
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 48,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'limitRows',
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 48,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 48,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 48,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 48,
                  'char' => 47,
                ),
                1 => 
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
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 49,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 49,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 49,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 49,
                  'char' => 38,
                ),
                2 => 
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
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 50,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'data',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 50,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 50,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 50,
                  'char' => 38,
                ),
                3 => 
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
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 51,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'page',
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 51,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 51,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 51,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 51,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 53,
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
                      'value' => 'items',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 53,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 53,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 53,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 53,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 53,
                'char' => 44,
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
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 54,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 54,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 54,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 55,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 58,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'less-equal',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'pageNumber',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 58,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 58,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 58,
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
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 59,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 59,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 60,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 63,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'less-equal',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'show',
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 63,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 63,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 63,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 63,
                'char' => 30,
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
                          'value' => 'The start page number is zero or less',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 64,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 64,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 64,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 65,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 67,
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
                  'variable' => 'n',
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
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 67,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 67,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 67,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 67,
                  'char' => 40,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'lastShowPage',
                  'expr' => 
                  array (
                    'type' => 'sub',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pageNumber',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 68,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 68,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 68,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 68,
                  'char' => 42,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'start',
                  'expr' => 
                  array (
                    'type' => 'mul',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'show',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 69,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'lastShowPage',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 69,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 69,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 69,
                  'char' => 47,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'pageItems',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 70,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 70,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 72,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'mod',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'n',
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 72,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'show',
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 72,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 72,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 72,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 72,
                'char' => 26,
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
                      'variable' => 'totalPages',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'int',
                        'right' => 
                        array (
                          'type' => 'list',
                          'left' => 
                          array (
                            'type' => 'add',
                            'left' => 
                            array (
                              'type' => 'div',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'n',
                                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                                'line' => 73,
                                'char' => 39,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'show',
                                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                                'line' => 73,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 73,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 73,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 73,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 73,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 73,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 73,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 74,
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
                      'variable' => 'totalPages',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'int',
                        'right' => 
                        array (
                          'type' => 'list',
                          'left' => 
                          array (
                            'type' => 'div',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'n',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 75,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'show',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 75,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 75,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 75,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 75,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 75,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 78,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'n',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 78,
                  'char' => 14,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 78,
                  'char' => 18,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 78,
                'char' => 18,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'less-equal',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'start',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 80,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'n',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 80,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 80,
                    'char' => 26,
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
                          'value' => 'items',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 81,
                          'char' => 23,
                        ),
                        'name' => 'seek',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'start',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 81,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 81,
                            'char' => 34,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 81,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 82,
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
                          'value' => 'items',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 83,
                          'char' => 23,
                        ),
                        'name' => 'seek',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 83,
                              'char' => 30,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 83,
                            'char' => 30,
                          ),
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 83,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 85,
                      'char' => 19,
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
                          'variable' => 'pageNumber',
                          'expr' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 85,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 85,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 86,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 89,
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
                      'variable' => 'i',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 89,
                        'char' => 22,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 89,
                      'char' => 22,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 91,
                  'char' => 17,
                ),
                2 => 
                array (
                  'type' => 'while',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'items',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 91,
                      'char' => 25,
                    ),
                    'name' => 'valid',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 91,
                    'char' => 34,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'pageItems',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'items',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 92,
                              'char' => 41,
                            ),
                            'name' => 'current',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 92,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 92,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 94,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'greater-equal',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'i',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 94,
                          'char' => 22,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'show',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 94,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 94,
                        'char' => 29,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 96,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 98,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'incr',
                          'variable' => 'i',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 98,
                          'char' => 24,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 100,
                      'char' => 21,
                    ),
                    3 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'items',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 100,
                          'char' => 23,
                        ),
                        'name' => 'next',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 100,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 101,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 102,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 105,
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
                  'variable' => 'next',
                  'expr' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pageNumber',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 105,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 105,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 105,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 105,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 107,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'next',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 107,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'totalPages',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 107,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 107,
                'char' => 30,
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
                        'type' => 'variable',
                        'value' => 'totalPages',
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 108,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 108,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 109,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 111,
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
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 111,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 111,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 111,
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
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 112,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 112,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 112,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 112,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 113,
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
                        'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                        'line' => 114,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 114,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 115,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 117,
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
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 117,
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
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 119,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_ITEMS',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 119,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 119,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'pageItems',
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 119,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 119,
                          'char' => 72,
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
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 120,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_TOTAL_ITEMS',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 120,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 120,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'n',
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 120,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 120,
                          'char' => 64,
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
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 121,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_LIMIT',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 121,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 121,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 121,
                              'char' => 68,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'limitRows',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 121,
                              'char' => 78,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 121,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 121,
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
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 122,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_FIRST_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 122,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 122,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 122,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 122,
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
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 123,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_PREVIOUS_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 123,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 123,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'previous',
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 123,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 123,
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
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 124,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_CURRENT_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 124,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 124,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'pageNumber',
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 124,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 124,
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
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 125,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_NEXT_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 125,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 125,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'next',
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 125,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 125,
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
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 126,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'PROPERTY_LAST_PAGE',
                              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                              'line' => 126,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 126,
                            'char' => 61,
                          ),
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'totalPages',
                            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                            'line' => 127,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                          'line' => 127,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                      'line' => 128,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                    'line' => 128,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 128,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
              'line' => 129,
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
                  'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                  'line' => 43,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
                'line' => 43,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
            'line' => 43,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
          'line' => 42,
          'last-line' => 130,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
      'line' => 37,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Paginator/Adapter/Model.zep',
    'line' => 37,
    'char' => 5,
  ),
);