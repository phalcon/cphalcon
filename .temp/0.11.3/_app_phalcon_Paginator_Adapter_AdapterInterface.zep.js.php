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
    'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Paginator\\Adapter',
    'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
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
        'name' => 'Phalcon\\Paginator\\RepositoryInterface',
        'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
        'line' => 13,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Paginator\\AdapterInterface
 *
 * Interface for Phalcon\\Paginator adapters
 *',
    'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'AdapterInterface',
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
          'name' => 'getLimit',
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
                'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
                'line' => 25,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
            'line' => 25,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'paginate',
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
                  'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
                  'line' => 30,
                  'char' => 56,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
                'line' => 30,
                'char' => 56,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
            'line' => 30,
            'char' => 56,
          ),
          'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
          'line' => 30,
          'last-line' => 34,
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
              'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
              'line' => 35,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Set the current page number
     *',
          'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
          'line' => 35,
          'last-line' => 39,
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
              'name' => 'limit',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
              'line' => 40,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Set current rows limit
     *',
          'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
          'line' => 40,
          'last-line' => 41,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
      'line' => 41,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Paginator/Adapter/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);