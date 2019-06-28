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
    'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cache\\Adapter',
    'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
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
        'alias' => 'CacheAdapterInterface',
        'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
        'line' => 13,
        'char' => 68,
      ),
    ),
    'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
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
        'name' => 'Phalcon\\Storage\\Adapter\\Redis',
        'alias' => 'StorageRedis',
        'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
        'line' => 14,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Redis adapter
 *',
    'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
    'line' => 19,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Redis',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'StorageRedis',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'CacheAdapterInterface',
        'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
        'line' => 20,
        'char' => 1,
      ),
    ),
    'file' => '/app/phalcon/Cache/Adapter/Redis.zep',
    'line' => 19,
    'char' => 5,
  ),
);