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
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 *',
    'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
    'line' => 19,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Domain\\Payload',
    'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
    'line' => 21,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Domain\\Payload\\Payload',
        'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
        'line' => 21,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
    'line' => 22,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Domain\\Payload\\PayloadInterface',
        'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
        'line' => 22,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
    'line' => 26,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Factory to create payload objects
 *',
    'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
    'line' => 27,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'PayloadFactory',
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
          ),
          'type' => 'method',
          'name' => 'newInstance',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Payload',
                'dynamic' => 0,
                'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
                'line' => 34,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
              'line' => 35,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Instantiate a new object
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
                  'value' => 'PayloadInterface',
                  'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
                  'line' => 33,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
                'line' => 33,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
          'line' => 32,
          'last-line' => 36,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
      'line' => 27,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Domain/Payload/PayloadFactory.zep',
    'line' => 27,
    'char' => 5,
  ),
);