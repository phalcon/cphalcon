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
    'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Di',
    'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
    'line' => 18,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This interface must be implemented in those classes that uses internally the
 * Phalcon\\Di that creates them
 *',
    'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'InjectionAwareInterface',
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
          'name' => 'setDI',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
                'line' => 24,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
              'line' => 24,
              'char' => 50,
            ),
          ),
          'docblock' => '**
     * Sets the dependency injector
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
            'line' => 24,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
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
          'name' => 'getDI',
          'docblock' => '**
     * Returns the internal dependency injector
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
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
                  'line' => 29,
                  'char' => 45,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
                'line' => 29,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
            'line' => 29,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
          'line' => 29,
          'last-line' => 30,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
      'line' => 30,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Di/InjectionAwareInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);