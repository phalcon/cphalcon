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
    'file' => '/app/phalcon/UrlInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/UrlInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\UrlInterface
 *',
    'file' => '/app/phalcon/UrlInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'UrlInterface',
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
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 24,
                'char' => 35,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/UrlInterface.zep',
              'line' => 24,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'args',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 24,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/UrlInterface.zep',
              'line' => 24,
              'char' => 48,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'local',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 24,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/UrlInterface.zep',
              'line' => 24,
              'char' => 67,
            ),
          ),
          'docblock' => '**
     * Generates a URL
     *
     * @param string|array uri
     * @param array|object args Optional arguments to be appended to the query string
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
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 24,
                'char' => 78,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/UrlInterface.zep',
            'line' => 24,
            'char' => 78,
          ),
          'file' => '/app/phalcon/UrlInterface.zep',
          'line' => 24,
          'last-line' => 28,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBasePath',
          'docblock' => '**
     * Returns a base path
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
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 29,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/UrlInterface.zep',
            'line' => 29,
            'char' => 44,
          ),
          'file' => '/app/phalcon/UrlInterface.zep',
          'line' => 29,
          'last-line' => 33,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBaseUri',
          'docblock' => '**
     * Returns the prefix for all the generated urls. By default /
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
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 34,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/UrlInterface.zep',
            'line' => 34,
            'char' => 43,
          ),
          'file' => '/app/phalcon/UrlInterface.zep',
          'line' => 34,
          'last-line' => 38,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBasePath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'basePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/UrlInterface.zep',
              'line' => 39,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets a base paths for all the generated paths
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
                  'value' => 'UrlInterface',
                  'file' => '/app/phalcon/UrlInterface.zep',
                  'line' => 39,
                  'char' => 68,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 39,
                'char' => 68,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/UrlInterface.zep',
            'line' => 39,
            'char' => 68,
          ),
          'file' => '/app/phalcon/UrlInterface.zep',
          'line' => 39,
          'last-line' => 43,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBaseUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'baseUri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/UrlInterface.zep',
              'line' => 44,
              'char' => 47,
            ),
          ),
          'docblock' => '**
     * Sets a prefix to all the urls generated
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
                  'value' => 'UrlInterface',
                  'file' => '/app/phalcon/UrlInterface.zep',
                  'line' => 44,
                  'char' => 66,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 44,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/UrlInterface.zep',
            'line' => 44,
            'char' => 66,
          ),
          'file' => '/app/phalcon/UrlInterface.zep',
          'line' => 44,
          'last-line' => 48,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'path',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 49,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/UrlInterface.zep',
              'line' => 49,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Generates a local path
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
                'file' => '/app/phalcon/UrlInterface.zep',
                'line' => 49,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/UrlInterface.zep',
            'line' => 49,
            'char' => 55,
          ),
          'file' => '/app/phalcon/UrlInterface.zep',
          'line' => 49,
          'last-line' => 50,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/UrlInterface.zep',
      'line' => 50,
      'char' => 1,
    ),
    'file' => '/app/phalcon/UrlInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);