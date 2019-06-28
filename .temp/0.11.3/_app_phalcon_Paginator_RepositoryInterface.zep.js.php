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
    'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Paginator',
    'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
    'line' => 18,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Paginator\\RepositoryInterface
 *
 * Interface for the repository of current state
 * Phalcon\\Paginator\\AdapterInterface::paginate()
 *',
    'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'RepositoryInterface',
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
          'name' => 'getAliases',
          'docblock' => '**
     * Gets the aliases for properties repository
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 33,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 33,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 33,
          'last-line' => 37,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCurrent',
          'docblock' => '**
     * Gets number of the current page
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 38,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 38,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFirst',
          'docblock' => '**
     * Gets number of the first page
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 43,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 43,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 43,
          'last-line' => 47,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getItems',
          'docblock' => '**
     * Gets the items on the current page
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 48,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 48,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLast',
          'docblock' => '**
     * Gets number of the last page
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 53,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 53,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 53,
          'last-line' => 57,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLimit',
          'docblock' => '**
     * Gets current rows limit
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 58,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 58,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 58,
          'last-line' => 62,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNext',
          'docblock' => '**
     * Gets number of the next page
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 63,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 63,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 63,
          'last-line' => 67,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPrevious',
          'docblock' => '**
     * Gets number of the previous page
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 68,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 68,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 68,
          'last-line' => 72,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTotalItems',
          'docblock' => '**
     * Gets the total number of items
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
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 73,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 73,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 73,
          'last-line' => 77,
          'char' => 19,
        ),
        9 => 
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
              'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
              'line' => 78,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets the aliases for properties repository
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
                  'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                  'line' => 78,
                  'char' => 71,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 78,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 78,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 78,
          'last-line' => 82,
          'char' => 19,
        ),
        10 => 
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
              'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
              'line' => 83,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Sets values for properties of the repository
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
                  'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                  'line' => 83,
                  'char' => 77,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
                'line' => 83,
                'char' => 77,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 83,
            'char' => 77,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 83,
          'last-line' => 84,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'PROPERTY_CURRENT_PAGE',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'current',
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 21,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 22,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'PROPERTY_FIRST_PAGE',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'first',
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 22,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 23,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'PROPERTY_ITEMS',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'items',
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 23,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 24,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'PROPERTY_LAST_PAGE',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'last',
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 24,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 25,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'PROPERTY_LIMIT',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'limit',
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 25,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 26,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'PROPERTY_NEXT_PAGE',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'next',
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 26,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 27,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'PROPERTY_PREVIOUS_PAGE',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'previous',
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 27,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 28,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'PROPERTY_TOTAL_ITEMS',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'total_items',
            'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
            'line' => 28,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
          'line' => 32,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
      'line' => 84,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Paginator/RepositoryInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);