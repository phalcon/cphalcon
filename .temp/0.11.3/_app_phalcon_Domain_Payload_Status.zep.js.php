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
    'file' => '/app/phalcon/Domain/Payload/Status.zep',
    'line' => 19,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Domain\\Payload',
    'file' => '/app/phalcon/Domain/Payload/Status.zep',
    'line' => 23,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Holds the status codes for the payload
 *',
    'file' => '/app/phalcon/Domain/Payload/Status.zep',
    'line' => 24,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Status',
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
            0 => 'final',
            1 => 'private',
          ),
          'type' => 'method',
          'name' => '__construct',
          'docblock' => '**
     * Instantiation not allowed.
     *',
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 50,
          'last-line' => 53,
          'char' => 26,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'ACCEPTED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'ACCEPTED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 26,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 27,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'AUTHENTICATED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'AUTHENTICATED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 27,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 28,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'AUTHORIZED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'AUTHORIZED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 28,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 29,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'CREATED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'CREATED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 29,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 30,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'DELETED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'DELETED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 30,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 31,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'ERROR',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'ERROR',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 31,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 32,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'FAILURE',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'FAILURE',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 32,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 33,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'FOUND',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'FOUND',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 33,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 34,
          'char' => 9,
        ),
        8 => 
        array (
          'type' => 'const',
          'name' => 'NOT_ACCEPTED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'NOT_ACCEPTED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 34,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 35,
          'char' => 9,
        ),
        9 => 
        array (
          'type' => 'const',
          'name' => 'NOT_AUTHENTICATED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'NOT_AUTHENTICATED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 35,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 36,
          'char' => 9,
        ),
        10 => 
        array (
          'type' => 'const',
          'name' => 'NOT_AUTHORIZED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'NOT_AUTHORIZED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 36,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 37,
          'char' => 9,
        ),
        11 => 
        array (
          'type' => 'const',
          'name' => 'NOT_CREATED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'NOT_CREATED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 37,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 38,
          'char' => 9,
        ),
        12 => 
        array (
          'type' => 'const',
          'name' => 'NOT_DELETED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'NOT_DELETED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 38,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 39,
          'char' => 9,
        ),
        13 => 
        array (
          'type' => 'const',
          'name' => 'NOT_FOUND',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'NOT_FOUND',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 39,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 40,
          'char' => 9,
        ),
        14 => 
        array (
          'type' => 'const',
          'name' => 'NOT_UPDATED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'NOT_UPDATED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 40,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 41,
          'char' => 9,
        ),
        15 => 
        array (
          'type' => 'const',
          'name' => 'NOT_VALID',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'NOT_VALID',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 41,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 42,
          'char' => 9,
        ),
        16 => 
        array (
          'type' => 'const',
          'name' => 'PROCESSING',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'PROCESSING',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 42,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 43,
          'char' => 9,
        ),
        17 => 
        array (
          'type' => 'const',
          'name' => 'SUCCESS',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'SUCCESS',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 43,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 44,
          'char' => 9,
        ),
        18 => 
        array (
          'type' => 'const',
          'name' => 'UPDATED',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'UPDATED',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 44,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 45,
          'char' => 9,
        ),
        19 => 
        array (
          'type' => 'const',
          'name' => 'VALID',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'VALID',
            'file' => '/app/phalcon/Domain/Payload/Status.zep',
            'line' => 45,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Domain/Payload/Status.zep',
          'line' => 49,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Domain/Payload/Status.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Domain/Payload/Status.zep',
    'line' => 24,
    'char' => 5,
  ),
);