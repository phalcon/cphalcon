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
    'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
        'line' => 13,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\BinderInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Binder
 *',
    'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'BinderInterface',
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
          'name' => 'bindToHandler',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'object',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
              'line' => 25,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
              'line' => 25,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'cacheKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
              'line' => 25,
              'char' => 80,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'methodName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
                'line' => 25,
                'char' => 107,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
              'line' => 25,
              'char' => 107,
            ),
          ),
          'docblock' => '**
     * Bind models into params in proper handler
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
                'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
                'line' => 25,
                'char' => 117,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
            'line' => 25,
            'char' => 117,
          ),
          'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
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
          'name' => 'getBoundModels',
          'docblock' => '**
     * Gets active bound models
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
                'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
                'line' => 30,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
            'line' => 30,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
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
          'name' => 'getCache',
          'docblock' => '**
     * Gets cache instance
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
                  'line' => 35,
                  'char' => 53,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
                'line' => 35,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
            'line' => 35,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
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
          'name' => 'setCache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cache',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
                'line' => 40,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
              'line' => 40,
              'char' => 54,
            ),
          ),
          'docblock' => '**
     * Sets cache instance
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
                  'value' => 'BinderInterface',
                  'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
                  'line' => 40,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
                'line' => 40,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
            'line' => 40,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
          'line' => 40,
          'last-line' => 41,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
      'line' => 41,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/BinderInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);