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
    'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation',
    'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
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
        'name' => 'Phalcon\\Validation\\Validation',
        'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This is a base class for combined fields validators
 *',
    'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'ValidatorCompositeInterface',
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
          'name' => 'getValidators',
          'docblock' => '**
     * Executes the validation
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
                'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
                'line' => 23,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
            'line' => 23,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'validate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'validation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Validation',
                'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
                'line' => 28,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
              'line' => 28,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
              'line' => 28,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Executes the validation
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
                'line' => 28,
                'char' => 73,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
            'line' => 28,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
          'line' => 28,
          'last-line' => 29,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
      'line' => 29,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Validation/ValidatorCompositeInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);