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
    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\MetaData',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
        'line' => 15,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
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
        'name' => 'Phalcon\\Cache\\AdapterFactory',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
    'line' => 24,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\MetaData\\Libmemcached
 *
 * Stores model meta-data in the Memcache.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
    'line' => 25,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Libmemcached',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'MetaData',
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
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'factory',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterFactory',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                'line' => 32,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
              'line' => 32,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                'line' => 32,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
              'line' => 32,
              'char' => 78,
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
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'persistentId',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                      'line' => 34,
                      'char' => 33,
                    ),
                  ),
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
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 34,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 34,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'persistentId',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 34,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 34,
                        'char' => 67,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'ph-mm-mcid-',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 34,
                          'char' => 80,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 34,
                        'char' => 80,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                    'line' => 34,
                    'char' => 81,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                  'line' => 34,
                  'char' => 81,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'prefix',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                      'line' => 35,
                      'char' => 27,
                    ),
                  ),
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
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 35,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 35,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 35,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 35,
                        'char' => 61,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'ph-mm-memc-',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 35,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 35,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                    'line' => 35,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                  'line' => 35,
                  'char' => 75,
                ),
                2 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'lifetime',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                      'line' => 36,
                      'char' => 29,
                    ),
                  ),
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
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 36,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 36,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'lifetime',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 36,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 36,
                        'char' => 63,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '172800',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 36,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 36,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                    'line' => 36,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                  'line' => 36,
                  'char' => 72,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'adapter',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'factory',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                      'line' => 37,
                      'char' => 47,
                    ),
                    'name' => 'newInstance',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'libmemcached',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 37,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 37,
                        'char' => 72,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                          'line' => 37,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                        'line' => 37,
                        'char' => 81,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                    'line' => 37,
                    'char' => 82,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                  'line' => 37,
                  'char' => 82,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
              'line' => 38,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\MetaData\\Libmemcached constructor
     *
     * @param array options
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
          'line' => 32,
          'last-line' => 42,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
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
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                    'line' => 45,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                    'line' => 45,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                  'line' => 45,
                  'char' => 23,
                ),
                'name' => 'clear',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                'line' => 45,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
              'line' => 47,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'reset',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
                'line' => 47,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
              'line' => 48,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Flush Memcache data and resets internal meta-data in order to regenerate it
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
            'line' => 44,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
          'line' => 43,
          'last-line' => 49,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Libmemcached.zep',
    'line' => 25,
    'char' => 5,
  ),
);