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
    'file' => '/app/phalcon/Collection/ReadCollection.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Collection',
    'file' => '/app/phalcon/Collection/ReadCollection.zep',
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
        'name' => 'Phalcon\\Collection\\Collection',
        'file' => '/app/phalcon/Collection/ReadCollection.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Collection/ReadCollection.zep',
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
        'name' => 'Phalcon\\Collection\\Exception',
        'file' => '/app/phalcon/Collection/ReadCollection.zep',
        'line' => 14,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Collection/ReadCollection.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Collection\\ReadCollection is a read only Collection object
 *',
    'file' => '/app/phalcon/Collection/ReadCollection.zep',
    'line' => 19,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'ReadCollection',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Collection',
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
          'name' => 'remove',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/ReadCollection.zep',
              'line' => 24,
              'char' => 42,
            ),
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
                      'value' => 'The object is read only',
                      'file' => '/app/phalcon/Collection/ReadCollection.zep',
                      'line' => 26,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Collection/ReadCollection.zep',
                    'line' => 26,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Collection/ReadCollection.zep',
                'line' => 26,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Collection/ReadCollection.zep',
              'line' => 27,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Delete the element from the collection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/ReadCollection.zep',
            'line' => 25,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/ReadCollection.zep',
          'line' => 24,
          'last-line' => 31,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/ReadCollection.zep',
              'line' => 32,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Collection/ReadCollection.zep',
              'line' => 32,
              'char' => 50,
            ),
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
                      'value' => 'The object is read only',
                      'file' => '/app/phalcon/Collection/ReadCollection.zep',
                      'line' => 34,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Collection/ReadCollection.zep',
                    'line' => 34,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Collection/ReadCollection.zep',
                'line' => 34,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Collection/ReadCollection.zep',
              'line' => 35,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set an element in the collection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Collection/ReadCollection.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Collection/ReadCollection.zep',
          'line' => 32,
          'last-line' => 36,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Collection/ReadCollection.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Collection/ReadCollection.zep',
    'line' => 19,
    'char' => 5,
  ),
);