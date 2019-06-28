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
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 *',
    'file' => '/app/phalcon/Http/Message/UriFactory.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/UriFactory.zep',
    'line' => 17,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\UriFactoryInterface',
        'file' => '/app/phalcon/Http/Message/UriFactory.zep',
        'line' => 17,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UriFactory.zep',
    'line' => 18,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\UriInterface',
        'file' => '/app/phalcon/Http/Message/UriFactory.zep',
        'line' => 18,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UriFactory.zep',
    'line' => 19,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Message\\Uri',
        'file' => '/app/phalcon/Http/Message/UriFactory.zep',
        'line' => 19,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UriFactory.zep',
    'line' => 23,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-17 UriFactory
 *',
    'file' => '/app/phalcon/Http/Message/UriFactory.zep',
    'line' => 24,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'UriFactory',
    'abstract' => 0,
    'final' => 1,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'UriFactoryInterface',
        'file' => '/app/phalcon/Http/Message/UriFactory.zep',
        'line' => 25,
        'char' => 1,
      ),
    ),
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
          'name' => 'createUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/UriFactory.zep',
                'line' => 30,
                'char' => 45,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UriFactory.zep',
              'line' => 30,
              'char' => 45,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Uri',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/UriFactory.zep',
                      'line' => 32,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Http/Message/UriFactory.zep',
                    'line' => 32,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/UriFactory.zep',
                'line' => 32,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/UriFactory.zep',
              'line' => 33,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a Locator object with all the helpers defined in anonynous
     * functions
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
                  'value' => 'UriInterface',
                  'file' => '/app/phalcon/Http/Message/UriFactory.zep',
                  'line' => 31,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/UriFactory.zep',
                'line' => 31,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/UriFactory.zep',
            'line' => 31,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/UriFactory.zep',
          'line' => 30,
          'last-line' => 34,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/UriFactory.zep',
      'line' => 24,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/UriFactory.zep',
    'line' => 24,
    'char' => 11,
  ),
);