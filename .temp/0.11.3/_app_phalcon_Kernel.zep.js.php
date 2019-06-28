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
    'file' => '/app/phalcon/Kernel.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Kernel.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class allows to change the internal behavior of the framework in runtime
 *',
    'file' => '/app/phalcon/Kernel.zep',
    'line' => 16,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Kernel',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'preComputeHashKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Kernel.zep',
              'line' => 24,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'cblock',
              'value' => '

        {

        RETURN_MM_NULL();

        }

        ',
              'file' => '/app/phalcon/Kernel.zep',
              'line' => 35,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Produces a pre-computed hash key based on a string. This function
     * produces different numbers in 32bit/64bit processors
     *
     * @return string
     *',
          'file' => '/app/phalcon/Kernel.zep',
          'line' => 24,
          'last-line' => 36,
          'char' => 26,
        ),
      ),
      'file' => '/app/phalcon/Kernel.zep',
      'line' => 16,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Kernel.zep',
    'line' => 16,
    'char' => 5,
  ),
);