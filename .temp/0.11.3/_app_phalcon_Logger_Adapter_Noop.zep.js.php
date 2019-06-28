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
    'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Adapter',
    'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
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
        'name' => 'Phalcon\\Logger\\Item',
        'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
    'line' => 28,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\Adapter\\Noop
 *
 * Adapter to store logs in plain text files
 *
 *```php
 * $logger = new \\Phalcon\\Logger\\Adapter\\Noop();
 *
 * $logger->log(\\Phalcon\\Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *
 * $logger->close();
 *```
 *',
    'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
    'line' => 29,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Noop',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
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
          'name' => 'close',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
                'line' => 36,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
              'line' => 37,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Closes the stream
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
                'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
                'line' => 35,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
            'line' => 35,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
          'line' => 34,
          'last-line' => 41,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'process',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Item',
                'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
                'line' => 42,
                'char' => 39,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
              'line' => 42,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Processes the message i.e. writes it to the file
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
            'line' => 43,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
          'line' => 42,
          'last-line' => 46,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
      'line' => 29,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/Adapter/Noop.zep',
    'line' => 29,
    'char' => 5,
  ),
);