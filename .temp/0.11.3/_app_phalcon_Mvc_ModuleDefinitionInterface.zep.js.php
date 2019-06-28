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
    'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
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
        'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\ModuleDefinitionInterface
 *
 * This interface must be implemented by class module definitions
 *',
    'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'ModuleDefinitionInterface',
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
          'name' => 'registerAutoloaders',
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
                'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
                'line' => 25,
                'char' => 63,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
                'line' => 25,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
              'line' => 25,
              'char' => 71,
            ),
          ),
          'docblock' => '**
     * Registers an autoloader related to the module
     *',
          'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
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
          'name' => 'registerServices',
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
                'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
                'line' => 30,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
              'line' => 30,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Registers services related to the module
     *',
          'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
          'line' => 30,
          'last-line' => 31,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
      'line' => 31,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/ModuleDefinitionInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);